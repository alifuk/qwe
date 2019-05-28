#pragma once
class feature
{
public:
	feature();
	enum FeatureType { IMG, ONEPOINT, Directory, ExistingFiles, DirectoryOnly };

	~feature();
};

