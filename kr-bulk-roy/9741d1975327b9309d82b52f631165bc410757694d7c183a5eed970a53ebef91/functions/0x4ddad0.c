
void FUN_004ddad0(int param_1,undefined1 param_2)

{
  uint *puVar1;
  void *_Dst;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = param_1;
  puVar1 = (uint *)(param_1 + 0x5ec8);
  _Dst = (void *)*puVar1;
  iVar6 = param_1;
  if (_Dst != *(void **)(param_1 + 0x5ecc)) {
    FID_conflict__memcpy(_Dst,*(void **)(param_1 + 0x5ecc),0);
    *(void **)(iVar4 + 0x5ecc) = _Dst;
    iVar6 = param_1;
  }
  param_1 = 0;
  if (0 < (int)(*(int *)(iVar6 + 0x5ebc) - *(int *)(iVar6 + 0x5eb8) & 0xfffffff8U)) {
    do {
      iVar5 = param_1;
      puVar2 = *(undefined4 **)(iVar4 + 0x5ecc);
      if (&param_1 < puVar2) {
        puVar3 = (undefined4 *)*puVar1;
        if (&param_1 < puVar3) goto LAB_004ddb62;
        if (puVar2 == *(undefined4 **)(iVar4 + 0x5ed0)) {
          FUN_006d6240();
        }
        if (*(undefined4 **)(iVar4 + 0x5ecc) != (undefined4 *)0x0) {
          **(undefined4 **)(iVar4 + 0x5ecc) =
               *(undefined4 *)(*puVar1 + ((int)&param_1 - (int)puVar3 >> 2) * 4);
        }
      }
      else {
LAB_004ddb62:
        if (puVar2 == *(undefined4 **)(iVar4 + 0x5ed0)) {
          FUN_006d6240();
        }
        param_1 = iVar5;
        if (*(int **)(iVar4 + 0x5ecc) != (int *)0x0) {
          **(int **)(iVar4 + 0x5ecc) = iVar5;
        }
      }
      *(int *)(iVar4 + 0x5ecc) = *(int *)(iVar4 + 0x5ecc) + 4;
      param_1 = param_1 + 1;
    } while (param_1 < *(int *)(iVar6 + 0x5ebc) - *(int *)(iVar6 + 0x5eb8) >> 3);
  }
  FUN_0089288b(param_2);
  if (*puVar1 != *(uint *)(iVar6 + 0x5ecc)) {
    FUN_0046dff0(*puVar1,*(uint *)(iVar6 + 0x5ecc));
  }
  return;
}

