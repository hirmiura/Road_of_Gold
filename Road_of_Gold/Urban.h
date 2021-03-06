#pragma once

#include"Citizen.h"
#include"Basket.h"
#include"Wallet.h"
#include"Energy.h"
#include"Sandglass.h"
#include"Seller.h"
#include"Buyer.h"

struct Node;
struct Wallet;
struct Pos;
struct Route;

struct Urban
{
	String	name;
	int		walletID;
	int		joinedNodeID;
	double	productivity;
	Sandglass	sandglass;
	Array<Energy>	energies;
	Array<Citizen>	citizens;
	Array<double>	jobEfficiency;
	Array<Route*>	ownRoutes;
	Array<Seller>	sellers;
	Array<Buyer>	buyers;
	Array<Basket>	baskets;

	Urban(const JSONValue& _json);
	void	sellItem(const Casket& _casket, int _price, int _ownerWalletID);
	void	sellItem(int _itemType, int _numItem, int _price, int _ownerWalletID);
	int		numItem(int _itemType) const;	//売られている数
	bool	isSoldOut(int _itemType) const;	//売り切れかどうか
	int		cost(int _itemType, int _numItem = 1) const;	//_numItem個買うのにかかる最低コスト	ないなら-1を返す
	void	buyItem(int _itemType, int _walletID, int _numItem = 1);
	int		id() const;
	Pos		pos() const;
	Circle	shape() const;
	bool	mouseOver() const;
	bool	leftClicked() const;
};

extern Array<Urban> urbans;

void	updateUrbans();
void	drawUrbans();