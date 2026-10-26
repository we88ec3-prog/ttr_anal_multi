
undefined4 FUN_008ebc60(int *param_1)

{
  ushort *puVar1;
  longlong lVar2;
  longlong lVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  ushort *puVar7;
  
  iVar4 = *param_1;
  puVar1 = (ushort *)(param_1 + 0xb);
  *(undefined1 *)(param_1 + 0x1b) = 0;
  piVar6 = param_1 + 3;
  puVar7 = puVar1;
  for (iVar5 = 7; iVar5 != 0; iVar5 = iVar5 + -1) {
    *(int *)puVar7 = *piVar6;
    piVar6 = piVar6 + 1;
    puVar7 = puVar7 + 2;
  }
  if ((*puVar1 != 0) && (*(short *)((int)param_1 + 0x2e) != 0)) {
    if ((*(byte *)(iVar4 + 0xb0) & 8) != 0) {
      iVar5 = FUN_008b7f40((uint)*puVar1 << 6,*(undefined2 *)(iVar4 + 0x44));
      param_1[0xc] = iVar5;
      iVar5 = FUN_008b7f40((uint)*(ushort *)((int)param_1 + 0x2e) << 6,*(undefined2 *)(iVar4 + 0x44)
                          );
      param_1[0xd] = iVar5;
      lVar2 = (longlong)(int)*(short *)(iVar4 + 0x46) * (longlong)iVar5;
      lVar2 = lVar2 + (ulonglong)((int)(lVar2 >> 0x3f) + 0x8000);
      param_1[0xe] = ((uint)lVar2 >> 0x10) + (int)((ulonglong)lVar2 >> 0x20) * 0x10000 + 0x20 &
                     0xffffffc0;
      lVar2 = (longlong)(int)*(short *)(iVar4 + 0x48) * (longlong)param_1[0xd];
      lVar2 = lVar2 + (ulonglong)((int)(lVar2 >> 0x3f) + 0x8000);
      param_1[0xf] = ((uint)lVar2 >> 0x10) + (int)((ulonglong)lVar2 >> 0x20) * 0x10000 + 0x20 &
                     0xffffffc0;
      lVar2 = (longlong)(int)*(short *)(iVar4 + 0x4a) * (longlong)param_1[0xd];
      lVar3 = lVar2 + (ulonglong)((int)(lVar2 >> 0x3f) + 0x8000);
      param_1[0x10] =
           ((uint)lVar3 >> 0x10) + (int)((ulonglong)lVar3 >> 0x20) * 0x10000 + 0x20 & 0xffffffc0;
      lVar2 = (longlong)(int)*(short *)(iVar4 + 0x4c) * (longlong)param_1[0xc];
      lVar2 = lVar2 + (ulonglong)((int)(lVar2 >> 0x3f) + 0x8000);
      param_1[0x11] =
           ((uint)lVar2 >> 0x10) + (int)((ulonglong)lVar2 >> 0x20) * 0x10000 + 0x20 & 0xffffffc0;
    }
    if (*puVar1 < *(ushort *)((int)param_1 + 0x2e)) {
      param_1[0x16] = param_1[0xd];
      *(undefined2 *)(param_1 + 0x14) = *(undefined2 *)((int)param_1 + 0x2e);
      iVar4 = FUN_008b7f40(*puVar1,*(undefined2 *)((int)param_1 + 0x2e));
      param_1[0x12] = iVar4;
      param_1[0x13] = 0x10000;
    }
    else {
      param_1[0x16] = param_1[0xc];
      *(ushort *)(param_1 + 0x14) = *puVar1;
      param_1[0x12] = 0x10000;
      iVar4 = FUN_008b7f40(*(undefined2 *)((int)param_1 + 0x2e),*puVar1);
      param_1[0x13] = iVar4;
    }
    *(undefined1 *)((int)param_1 + 0x12d) = 0;
    *(undefined1 *)(param_1 + 0x1b) = 1;
    return 0;
  }
  return 0x97;
}

