
void FUN_005203e0(int param_1,int param_2,undefined4 param_3,code *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  char cVar4;
  int in_EAX;
  int iVar5;
  
  iVar3 = in_EAX;
  while( true ) {
    iVar5 = iVar3 * 2 + 2;
    if (param_2 <= iVar5) break;
    iVar1 = param_1 + iVar5 * 0x14;
    cVar4 = (*param_4)(iVar1,iVar1 + -0x14);
    if (cVar4 != '\0') {
      iVar5 = iVar3 * 2 + 1;
    }
    puVar2 = (undefined4 *)(param_1 + iVar5 * 0x14);
    *(undefined4 *)(param_1 + iVar3 * 0x14) = *puVar2;
    FUN_004fcdc0(puVar2 + 1);
    iVar3 = iVar5;
  }
  if (iVar5 == param_2) {
    *(undefined4 *)(param_1 + iVar3 * 0x14) = *(undefined4 *)(param_1 + -0x14 + param_2 * 0x14);
    FUN_004fcdc0(param_1 + param_2 * 0x14 + -0x10);
  }
  FUN_00520570(param_1,in_EAX,param_3,param_4);
  return;
}

