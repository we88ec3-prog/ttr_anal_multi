
int FUN_00703a60(int param_1,char *param_2,int param_3)

{
  char cVar1;
  char *in_EAX;
  int iVar2;
  uint uVar3;
  
  iVar2 = FUN_00703c30(param_1);
  if (iVar2 == 0) {
    while (in_EAX < *(char **)(param_1 + 4)) {
      cVar1 = *param_2;
      if (cVar1 == '%') {
        uVar3 = FUN_00703690();
LAB_00703aca:
        if (uVar3 == 0) break;
      }
      else if (cVar1 != '.') {
        if (cVar1 == '[') {
          uVar3 = FUN_007037a0(*in_EAX,param_3 + -1);
        }
        else {
          uVar3 = (uint)(cVar1 == *in_EAX);
        }
        goto LAB_00703aca;
      }
      in_EAX = in_EAX + 1;
      iVar2 = FUN_00703c30(param_1,in_EAX,param_3 + 1);
      if (iVar2 != 0) {
        return iVar2;
      }
    }
    iVar2 = 0;
  }
  return iVar2;
}

