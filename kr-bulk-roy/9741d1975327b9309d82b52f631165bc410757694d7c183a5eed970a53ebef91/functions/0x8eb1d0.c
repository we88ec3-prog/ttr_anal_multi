
undefined4 FUN_008eb1d0(int param_1,int param_2,uint param_3)

{
  longlong lVar1;
  int in_EAX;
  int iVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint local_10;
  uint local_c;
  
  iVar2 = *(int *)(param_1 + 0xc);
  uVar5 = (uint)*(short *)(iVar2 + 0x16);
  bVar3 = *(byte *)(in_EAX + 4) & 200;
  if ((bVar3 != 0) && (param_3 < uVar5)) {
    iVar8 = *(int *)(iVar2 + 0x18) + param_3 * 8;
    iVar7 = uVar5 - param_3;
    do {
      FUN_008b9510(iVar8,in_EAX + 0x10);
      iVar8 = iVar8 + 8;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  if ((*(ushort *)(in_EAX + 4) & 2) == 0) {
    uVar4 = *(int *)(in_EAX + 8) + param_2;
    uVar6 = *(int *)(in_EAX + 0xc) + param_3;
    if ((param_3 <= uVar4) || (uVar5 <= uVar6)) {
      return 0x15;
    }
    iVar2 = *(int *)(iVar2 + 0x18);
    local_c = *(int *)(iVar2 + uVar4 * 8) - *(int *)(iVar2 + uVar6 * 8);
    local_10 = *(int *)(iVar2 + 4 + uVar4 * 8) - *(int *)(iVar2 + 4 + uVar6 * 8);
  }
  else {
    local_c = *(uint *)(in_EAX + 8);
    local_10 = *(uint *)(in_EAX + 0xc);
    if ((local_c == 0) && (local_10 == 0)) {
      return 0;
    }
    if ((bVar3 != 0) && ((*(ushort *)(in_EAX + 4) & 0x800) != 0)) {
      iVar2 = FUN_008ba200(*(undefined4 *)(in_EAX + 0x10),*(undefined4 *)(in_EAX + 0x14));
      iVar8 = FUN_008ba200(*(undefined4 *)(in_EAX + 0x1c),*(undefined4 *)(in_EAX + 0x18));
      lVar1 = (longlong)(int)local_c * (longlong)iVar2 +
              (ulonglong)((int)((longlong)(int)local_c * (longlong)iVar2 >> 0x3f) + 0x8000);
      local_c = ((uint)lVar1 >> 0x10) + (int)((ulonglong)lVar1 >> 0x20) * 0x10000;
      lVar1 = (longlong)(int)local_10 * (longlong)iVar8 +
              (ulonglong)((int)((longlong)(int)local_10 * (longlong)iVar8 >> 0x3f) + 0x8000);
      local_10 = ((uint)lVar1 >> 0x10) + (int)((ulonglong)lVar1 >> 0x20) * 0x10000;
    }
    if ((*(byte *)(param_1 + 0x10) & 1) == 0) {
      lVar1 = (longlong)(int)local_c * (longlong)*(int *)(*(int *)(param_1 + 4) + 0x30);
      lVar1 = lVar1 + (ulonglong)((int)(lVar1 >> 0x3f) + 0x8000);
      local_c = ((uint)lVar1 >> 0x10) + (int)((ulonglong)lVar1 >> 0x20) * 0x10000;
      lVar1 = (longlong)(int)local_10 * (longlong)*(int *)(*(int *)(param_1 + 4) + 0x34);
      lVar1 = lVar1 + (ulonglong)((int)(lVar1 >> 0x3f) + 0x8000);
      local_10 = ((uint)lVar1 >> 0x10) + (int)((ulonglong)lVar1 >> 0x20) * 0x10000;
      if ((*(byte *)(in_EAX + 4) & 4) != 0) {
        local_c = local_c + 0x20 & 0xffffffc0;
        local_10 = local_10 + 0x20 & 0xffffffc0;
      }
    }
  }
  if ((local_c != 0) || (local_10 != 0)) {
    FUN_008eae10();
  }
  return 0;
}

