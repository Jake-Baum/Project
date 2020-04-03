#pragma once

struct UniformIds
{
  unsigned int mvpId;
  unsigned int cameraPositionId;
  unsigned int normalMatrixId;
};

class Shaders
{
public:
  unsigned int programId;
  UniformIds uniformIds;
};