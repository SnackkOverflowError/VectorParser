//
// Created by adi on 04/07/19.
//

#include <iostream>
#include "parser.h"
#include <vector>


dirVec::dirVec(double x, double y, double z) : x(x), y(y), z(z) {}

point::point(double x, double y, double z) : x(x), y(y), z(z) {}
dirVec point::minus(point b)
{
    return {b.x-x, b.y - y, b.z - z};
}

vec::vec(point a, point b)
{
    center = a;
    dir = a.minus(b);
}
vec::vec(dirVec dirP, point a)
{
    dir = dirP;
    center = a;
}

line::line(int lineNum, std::string lineVal) : lineNum(lineNum), lineVal(lineVal) {}

point parser::makePoint(std::string line)
{
    if(line.find('{') == std::string::npos)
    {
        if(points.count(line) > 0)
        {
            return points[line];
        }
        else
        {
            //error
        }
    }
    else
    {
        // std::cout << line << std::endl;
        line = line.substr(line.find('{') + 1); //line now is ####,#####,####}
        line = line.substr(0,line.length()- 1);

        //  std::cout << line << std::endl;
        double x = std::stod(line.substr(0,line.find(',')));
        //std::cout << x << std::endl;
        line = line.substr(line.find(',') + 1);
        double y = std::stod(line.substr(0, line.find(',')));
        //std::cout << y << std::endl;
        line = line.substr(line.find(',') + 1);
        double z = std::stod(line);
        // std::cout << z << std::endl;

        return {x,y,z};
    }




}

void parser::addPoint(std::string l) {
    std::string name = l.substr(0, l.find("=>"));
    points[name] = makePoint(l);
}



int parser::count(std::string l, std::string regex) {

    int x = 0;
    for(; l.find(regex) != std::string::npos; x++)
    {
        l = l.substr(l.find(regex) + regex.length());
    }
    return x;
}

dirVec parser::makeDirVec(std::string line) {

    if(line.find('{') == std::string::npos)
    {
        if(dirVecs.count(line) > 0)
        {
            return dirVecs[line];
        }
        else
        {
            //error
        }
    }
    else
    {
        //std::cout << "code made it here" << std::endl;
        // std::cout << line << std::endl;
        line = line.substr(line.find('{') + 1); //line now is ####,#####,####}
        //std::cout << line << std::endl;
        line = line.substr(0,line.length()- 1);


        // std::cout << line << std::endl;
        double x = std::stod(line.substr(0,line.find(',')));
        // std::cout << x << std::endl;
        line = line.substr(line.find(',') + 1);
        double y = std::stod(line.substr(0, line.find(',')));
        // std::cout << y << std::endl;
        line = line.substr(line.find(',') + 1);
        double z = std::stod(line);
        //  std::cout << z << std::endl;

        return {x,y,z};
    }

}

void dirVec::printInfo() {
    std::cout << "{" << x << ", " << y << ", " << z << "}" << std::endl;
}
void point::printInfo() {
    std::cout << "{" << x << ", " << y << ", " << z << "}" << std::endl;
}
void vec::printInfo() {
   std::cout << "Center: ";
   center.printInfo();
   std::cout << "dirVec: ";
   dir.printInfo();
}
void parser::addVector(std::string l) {
    std::string name = l.substr(0, l.find("=>"));
    vecs[name] = makeVector(l);
}
void parser::error(std::string errMsg) {
    std::cout << "error on line " << currentLineNum << std::endl;

    std::cout << "line contents: " << std::endl;
    std::cout << currentLineVal << std::endl;

    std::cout << "Error Message: " << std::endl;
    std::cout << errMsg << std::endl;

}
vec parser::makeVector(std::string l) {


    std::vector<std::string> args;
    l = l.substr(l.find("v{") + 2); //line now is ####,#####,####}
    l = l.substr(0,l.length()- 1);

    args = seperateArgs(l);
    std::cout << "args" << std::endl;
    for(auto&& x: args)
    {
        std::cout << x << std::endl;
    }
    if(args.size() == 1)
    {
        std::cout << "size == 1" << std::endl;
        return {makeDirVec(args[0]),{0,0,0}};
    }
    else
    {
        std::map<std::string,std::string> params;
        for(auto& p : args) {
            if (p.find("pt{") != std::string::npos || points.count(p) ==1)
            {
                //parameter is a point
                if(params.count("ptA") == 0)
                {
                    std::cout << "assigning ptA" << std::endl;
                    params["ptA"] = p;
                }
                else
                {
                    std::cout << "assigning ptB" << std::endl;
                    params["ptB"] = p;
                }

            }
            else if(p.find("dv{") != std::string::npos || dirVecs.count(p) ==1)
            {
                //parameter is a dirVec
                std::cout << "assiging dv" << std::endl;
                params["dv"] = p;
            }
            else
            {
                //parameter is neither and is wrong ERROR
                //BRUH sound effect #2
            }
        }
        if(params.count("ptA") == 1)
        {
            //point A was found
            if(params.count("dv") == 1 )
            {
                return {makeDirVec(params["dv"]), makePoint(params["ptA"])};
            }
            else if(params.count("ptB") == 1)
            {
                return {makePoint(params["ptA"]), makePoint(params["ptB"])};
            }
            else
            {
                //i dunno man
            }

        }
        else
        {
            //error, you need a point A
        }


    }

}
std::string parser::replace(std::string newS, std::string oldS, std::string p) {

        while(p.find(oldS) != std::string::npos)
        {
            p = p.substr(0,p.find(oldS)) + newS + p.substr(p.find(oldS) + 1);
        }
    return p;
}
std::vector<std::string> parser::seperateArgs(std::string l) {
    std::vector<std::string> args;
    int beginArg = 0;
    bool ignore = false; //for ignoring parameters in pt and dv definitions

    for(int x = 0; x < l.length(); x++)
    {
        // std::cout << x << " : " << beginArg << std::endl;
        std::string current = l.substr(x,1);
        if(current.compare("{") == 0)
        {
            ignore = true;
        }
        else if(current.compare("}") == 0)
        {
            ignore = false;
        }
        else if(current.compare(",") == 0 && !ignore)
        {
            args.push_back(l.substr(beginArg, x - beginArg));
            beginArg = x;
            //std::cout << "special" << x << " : " << beginArg << std::endl;

        }
        else
        {
            //basically any other character, we don't really care about them.
        }
        if(x == l.length() - 1)
        {
            args.push_back(l.substr(beginArg + 1,x - beginArg + 1));
            //std::cout << x << " : " << beginArg << std::endl;
        }
    }
    return args;
}
void parser::addDirVec(std::string line) {
    std::string name = line.substr(0,line.find("=>"));
    dirVecs[name] = makeDirVec(line);
}

bool parser::readLine(line l) {
    currentLineVal = l.lineVal;
    currentLineNum = l.lineNum;
    std::string line = replace(""," ",l.lineVal);

    if(line.find("=>"))
    {
        if(line.find("pn{"))
        {
            //addPlane(line);
        }
        else if(line.find("v{"))
        {
            addVector(line);
        }
        else if(line.find("pt{"))
        {
            addPoint(line);
        }
        else if(line.find("dv{"))
        {
            addDirVec(line);
        }
        else
        {
            //bruh sound effect #3
            error("Constructor not recognized");
        }

    }
    else
    {
        if(line.find("display"))
        {
            displayAll();
        }
    }

    return err;
}
void parser::displayAll() {
    std::cout << "points: " << std::endl;
    for( std::pair<std::string, point> e : points)
    {
        std::cout << "----------------------------------------" << std::endl;
        std::cout << e.first << std::endl;
        e.second.printInfo();
    }
    std::cout << "Direction Vectors: " << std::endl;
    for( std::pair<std::string, dirVec> e : dirVecs)
    {
        std::cout << "----------------------------------------" << std::endl;
        std::cout << e.first << std::endl;
        e.second.printInfo();
    }
    std::cout << "Vectors: " << std::endl;
    for( std::pair<std::string, vec> e : vecs)
    {
        std::cout << "----------------------------------------" << std::endl;
        std::cout << e.first << std::endl;
        e.second.printInfo();
    }
    std::cout << "planes: " << std::endl;
    for( std::pair<std::string, plane> e : planes)
    {
        std::cout << "----------------------------------------" << std::endl;
        std::cout << e.first << std::endl;
        e.second.printInfo();
    }

}

