
bool FUN_008b8270(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = param_1;
  if (param_1 < 0) {
    iVar2 = -param_1;
  }
  iVar1 = param_2;
  if (param_2 < 0) {
    iVar1 = -param_2;
  }
  iVar3 = param_3;
  if (param_3 < 0) {
    iVar3 = -param_3;
  }
  iVar4 = param_4;
  if (param_4 < 0) {
    iVar4 = -param_4;
  }
  param_3 = param_3 + param_1;
  if (param_3 < 0) {
    param_3 = -param_3;
  }
  param_2 = param_2 + param_4;
  if (param_2 < 0) {
    param_2 = -param_2;
  }
  return ((iVar3 + iVar4) - (param_3 + param_2)) + iVar1 + iVar2 < param_3 + param_2 >> 4;
}

