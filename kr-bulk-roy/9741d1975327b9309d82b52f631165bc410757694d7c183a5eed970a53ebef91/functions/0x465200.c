
void FUN_00465200(int param_1)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  undefined4 uVar3;
  
  if ((*(int *)(param_1 + 0x10) == 0x57b) &&
     ((uVar1 = *(uint *)(param_1 + 8), 999 < uVar1 || (uVar1 < *(int *)(in_ECX + 0x180) + 1000U))))
  {
    param_1 = uVar1 - 1000;
    FUN_00466360(&param_1);
    if ((in_ECX != *(int *)(in_ECX + 0x174)) && (iVar2 = *(int *)(in_ECX + 0x14) + -1, iVar2 == 0))
    {
      uVar3 = *(undefined4 *)(in_ECX + 0x18);
      FUN_00464f70(uVar3,0);
      FUN_006c8c80(uVar3,iVar2);
    }
  }
  return;
}

