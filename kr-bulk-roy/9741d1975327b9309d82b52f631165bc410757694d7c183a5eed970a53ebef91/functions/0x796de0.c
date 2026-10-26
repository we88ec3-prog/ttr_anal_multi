
int FUN_00796de0(int param_1,int param_2,undefined4 param_3)

{
  byte bVar1;
  int in_EAX;
  int iVar2;
  undefined4 in_ECX;
  int iVar3;
  
  if (param_2 <= param_1) {
    in_ECX = param_3;
  }
  iVar2 = param_2;
  switch(in_ECX) {
  case 1:
    if (param_2 <= param_1) {
      iVar2 = param_1;
    }
    if (in_EAX <= param_2) {
      return in_EAX;
    }
    break;
  case 2:
  case 3:
    iVar3 = (in_EAX - param_1) + -1;
    if (0 < iVar3) {
      iVar3 = (param_2 - param_1) % iVar3;
      if (param_1 <= param_2) {
        return iVar3 + param_1;
      }
      return iVar3 + in_EAX;
    }
    break;
  case 4:
    bVar1 = FUN_00796da0();
    iVar3 = (in_EAX - param_1) + -1;
    if (0 < iVar3) {
      iVar3 = (param_2 - param_1) % iVar3;
      iVar2 = iVar3 + param_1;
      if (param_2 < param_1) {
        iVar2 = iVar3 + in_EAX;
      }
    }
    if ((bVar1 & 1) != 0) {
      iVar2 = in_EAX + (param_1 - iVar2);
    }
  }
  return iVar2;
}

