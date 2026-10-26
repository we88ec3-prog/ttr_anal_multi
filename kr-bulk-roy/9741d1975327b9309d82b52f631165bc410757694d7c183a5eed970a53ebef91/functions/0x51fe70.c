
void FUN_0051fe70(int param_1,int param_2,code *param_3)

{
  char cVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = (param_2 - in_EAX) / 0x14;
  if (iVar2 < 0x29) {
    cVar1 = (*param_3)(param_1);
    if (cVar1 != '\0') {
      FUN_00520060();
    }
    cVar1 = (*param_3)(param_2,param_1);
    if (cVar1 != '\0') {
      FUN_00520060();
    }
    cVar1 = (*param_3)(param_1);
    if (cVar1 != '\0') {
      FUN_00520060();
    }
  }
  else {
    iVar2 = iVar2 + 1;
    iVar3 = (int)(iVar2 + (iVar2 >> 0x1f & 7U)) >> 3;
    iVar2 = iVar3 * 0x14 + in_EAX;
    cVar1 = (*param_3)(iVar2);
    if (cVar1 != '\0') {
      FUN_00520060();
    }
    cVar1 = (*param_3)(iVar3 * 0x28 + in_EAX,iVar2);
    if (cVar1 != '\0') {
      FUN_00520060();
    }
    cVar1 = (*param_3)(iVar2);
    if (cVar1 != '\0') {
      FUN_00520060();
    }
    iVar4 = param_1 + iVar3 * -0x14;
    cVar1 = (*param_3)(param_1,iVar4);
    if (cVar1 != '\0') {
      FUN_00520060();
    }
    cVar1 = (*param_3)(iVar3 * 0x14 + param_1,param_1);
    if (cVar1 != '\0') {
      FUN_00520060();
    }
    cVar1 = (*param_3)(param_1,iVar4);
    if (cVar1 != '\0') {
      FUN_00520060();
    }
    iVar4 = param_2 + iVar3 * -0x28;
    iVar3 = param_2 + iVar3 * -0x14;
    cVar1 = (*param_3)(iVar3,iVar4);
    if (cVar1 != '\0') {
      FUN_00520060();
    }
    cVar1 = (*param_3)(param_2,iVar3);
    if (cVar1 != '\0') {
      FUN_00520060();
    }
    cVar1 = (*param_3)(iVar3,iVar4);
    if (cVar1 != '\0') {
      FUN_00520060();
    }
    cVar1 = (*param_3)(param_1,iVar2);
    if (cVar1 != '\0') {
      FUN_00520060();
    }
    cVar1 = (*param_3)(iVar3,param_1);
    if (cVar1 != '\0') {
      FUN_00520060();
    }
    cVar1 = (*param_3)(param_1,iVar2);
    if (cVar1 != '\0') {
      FUN_00520060();
      return;
    }
  }
  return;
}

