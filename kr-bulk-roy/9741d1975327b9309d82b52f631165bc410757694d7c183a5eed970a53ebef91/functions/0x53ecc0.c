
void FUN_0053ecc0(undefined4 param_1,uint param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int in_ECX;
  int unaff_EDI;
  undefined4 uVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093af9e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb73b8 & 1) == 0) {
    DAT_00fb73b8 = DAT_00fb73b8 | 1;
    local_8 = 0;
    FUN_00560170(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd110);
  }
  local_8 = 0xffffffff;
  if (DAT_00fb73e8 == 0) {
    param_2 = param_2 & 0xffff;
    FUN_0082ef00(&param_2);
    if (((in_ECX != *(int *)(unaff_EDI + 4)) && (-1 < in_ECX)) &&
       (iVar1 = **(int **)(in_ECX + 0x10), in_ECX < (*(int **)(in_ECX + 0x10))[1] - iVar1 >> 2)) {
      iVar1 = FUN_00527040(*(undefined4 *)(iVar1 + in_ECX * 4));
      puVar2 = (undefined4 *)(iVar1 + 4);
      if (7 < *(uint *)(iVar1 + 0x18)) {
        puVar2 = (undefined4 *)*puVar2;
      }
      uVar4 = 0;
      uVar3 = FUN_0048a1d0(puVar2,0);
      FUN_0055ae70(uVar3,puVar2,uVar4);
    }
  }
  ExceptionList = local_10;
  return;
}

