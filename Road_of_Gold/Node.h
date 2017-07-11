#pragma once
#include "Pos.h"

struct Node;
struct Region;

struct Path
{
	Path::Path(const int& _parentNodeID, const int& _childNodeID);
	Node&	getChild() const;
	Node&	getParent() const;
	Line	getLine() const;

	int		id;
	double	len;
	int		parentNodeID;
	int		childNodeID;

};
extern Array<Path*> paths;

struct Node
{
	Node::Node(const int& _id, const Pos& _pos);
	bool	isCoast() const;
	void	draw(const Color& _color) const;
	Region&	getJoinedRegion() const;

	int		id;
	int		joinedRegionID;
	int		ownUrbanID;
	bool	isSea;
	Pos		pos;
	bool	isScaned, isInQueue;
	double	cost;
	int		fromNodeID;
	Array<Path> paths;
};
extern Array<Node> nodes;
void	loadNodeMap(const FilePath& _filePath);
void	setPlanetToNodes();

struct Region
{
	Region(const int& _id);

	Color	color;
	int		id;
	int		numNodes;
	bool	hasCity;
};
extern Array<Region> regions;