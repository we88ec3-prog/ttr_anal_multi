
undefined4 FUN_004b3600(undefined4 *param_1,ushort *param_2)

{
  undefined4 *puVar1;
  void *_Dst;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  ushort *puVar5;
  uint uVar6;
  uint local_8;
  
  iVar3 = DAT_00fe18f8;
  *(undefined4 *)(DAT_00fe18f8 + 0xc) = *param_1;
  *(undefined2 *)(iVar3 + 0x10) = *(undefined2 *)(param_1 + 1);
  *(undefined1 *)(iVar3 + 0x12) = *(undefined1 *)((int)param_1 + 6);
  if (param_2 < 7) {
    param_2 = (ushort *)0x0;
  }
  else {
    param_2 = (ushort *)((int)param_2 - 7U >> 1);
  }
  _Dst = *(void **)(iVar3 + 0x14);
  puVar1 = (undefined4 *)(iVar3 + 0x18);
  if (_Dst != *(void **)(iVar3 + 0x18)) {
    FID_conflict__memcpy(_Dst,*(void **)(iVar3 + 0x18),0);
    iVar3 = DAT_00fe18f8;
    *puVar1 = _Dst;
  }
  if (param_2 != (ushort *)0x0) {
    puVar5 = (ushort *)((int)param_1 + 7);
    local_8 = (uint)param_2;
    do {
      uVar6 = (uint)*puVar5;
      puVar1 = *(undefined4 **)(iVar3 + 0x18);
      iVar4 = iVar3;
      param_1 = (undefined4 *)uVar6;
      param_2 = puVar5;
      if (&param_1 < puVar1) {
        puVar2 = *(undefined4 **)(iVar3 + 0x14);
        if (&param_1 < puVar2) goto LAB_004b36cd;
        if (puVar1 == *(undefined4 **)(iVar3 + 0x1c)) {
          FUN_006d6240();
          iVar4 = DAT_00fe18f8;
        }
        if (*(undefined4 **)(iVar3 + 0x18) != (undefined4 *)0x0) {
          **(undefined4 **)(iVar3 + 0x18) =
               *(undefined4 *)(*(uint *)(iVar3 + 0x14) + ((int)&param_1 - (int)puVar2 >> 2) * 4);
        }
      }
      else {
LAB_004b36cd:
        if (puVar1 == *(undefined4 **)(iVar3 + 0x1c)) {
          FUN_006d6240();
          iVar4 = DAT_00fe18f8;
        }
        if (*(uint **)(iVar3 + 0x18) != (uint *)0x0) {
          **(uint **)(iVar3 + 0x18) = uVar6;
        }
      }
      *(int *)(iVar3 + 0x18) = *(int *)(iVar3 + 0x18) + 4;
      puVar5 = param_2 + 1;
      local_8 = local_8 - 1;
      iVar3 = iVar4;
    } while (local_8 != 0);
  }
  return 0;
}

