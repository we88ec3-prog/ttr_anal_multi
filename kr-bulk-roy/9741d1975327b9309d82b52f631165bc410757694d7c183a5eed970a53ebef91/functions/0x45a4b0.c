
void FUN_0045a4b0(void)

{
  int *piVar1;
  void *_Dst;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int in_ECX;
  uint uVar6;
  
  piVar1 = (int *)(in_ECX + 0xf0);
  _Dst = (void *)*piVar1;
  if (_Dst != *(void **)(in_ECX + 0xf4)) {
    FID_conflict__memcpy(_Dst,*(void **)(in_ECX + 0xf4),0);
    *(void **)(in_ECX + 0xf4) = _Dst;
  }
  FUN_00684010();
  iVar2 = *(int *)(*(int *)(in_ECX + 0xec) + 0xcc);
  if (iVar2 != 0) {
    FUN_00408920(iVar2,*(int *)(in_ECX + 0xf4) - *piVar1 >> 2);
  }
  uVar6 = 0;
  if (*(int *)(in_ECX + 0xf4) - *piVar1 >> 2 != 0) {
    do {
      iVar2 = *(int *)(*(int *)(in_ECX + 0xec) + 0xcc);
      if (((iVar2 == 0) || ((int)uVar6 < 0)) ||
         (*(int *)(iVar2 + 0xac) - *(int *)(iVar2 + 0xa8) >> 2 <= (int)uVar6)) {
        uVar5 = 0;
      }
      else {
        uVar5 = *(undefined4 *)(*(int *)(iVar2 + 0xa8) + uVar6 * 4);
      }
      *(undefined4 *)(*piVar1 + uVar6 * 4) = uVar5;
      (**(code **)(**(int **)(*piVar1 + uVar6 * 4) + 0x198))(0x96);
      uVar6 = uVar6 + 1;
    } while (uVar6 < (uint)(*(int *)(in_ECX + 0xf4) - *piVar1 >> 2));
  }
  piVar1 = *(int **)(in_ECX + 0xec);
  puVar3 = (undefined4 *)piVar1[0x19];
  for (puVar4 = (undefined4 *)*puVar3; puVar4 != puVar3; puVar4 = (undefined4 *)*puVar4) {
    iVar2 = puVar4[2];
    if ((*(int *)(iVar2 + 0x60) != 0) && ((*(int **)(iVar2 + 0x1c))[2] != 6)) {
      (**(code **)(**(int **)(iVar2 + 0x1c) + 0x30))(iVar2);
    }
  }
  (**(code **)(*piVar1 + 0x128))();
  return;
}

