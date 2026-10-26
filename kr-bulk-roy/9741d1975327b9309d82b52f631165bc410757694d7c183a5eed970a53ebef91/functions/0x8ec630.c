
void FUN_008ec630(int param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  piVar1 = (int *)(*(int *)(param_1 + 0x180) + param_2 * 4);
  uVar2 = FUN_008ec480();
  iVar3 = FUN_008b7f40(param_3,uVar2);
  *piVar1 = *piVar1 + iVar3;
  return;
}

