
void FUN_006bc850(void)

{
  char cVar1;
  void *_Dst;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iStack_38;
  int iStack_34;
  undefined1 auStack_28 [4];
  undefined4 *puStack_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_009424a8;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_007459c0(DAT_00d61f20 ^ (uint)&stack0xffffffb0);
  uVar7 = 1;
  puVar5 = (undefined4 *)(in_ECX + 0x98);
  do {
    (**(code **)(*(int *)*puVar5 + 0x198))(uVar7);
    uVar7 = uVar7 + 1;
    puVar5 = puVar5 + 1;
  } while (uVar7 < 10);
  puVar5 = (undefined4 *)(in_ECX + 0xc0);
  iVar6 = 5;
  do {
    (**(code **)(*(int *)*puVar5 + 0x1a0))();
    puVar5 = puVar5 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  _Dst = *(void **)(in_ECX + 0xf4);
  if (_Dst != *(void **)(in_ECX + 0xf8)) {
    FID_conflict__memcpy(_Dst,*(void **)(in_ECX + 0xf8),0);
    *(void **)(in_ECX + 0xf8) = _Dst;
  }
  iVar6 = DAT_00fe18f8;
  *(uint *)(in_ECX + 0xd8) = (uint)*(byte *)(DAT_00fe18f8 + 0x12);
  iVar6 = FUN_005082b0(iVar6,auStack_28);
  uStack_c = 0;
  if (in_ECX + 0xe4 != iVar6) {
    piVar2 = *(int **)(*(int *)(in_ECX + 0xe8) + 4);
    cVar1 = *(char *)((int)piVar2 + 0x11);
    while (cVar1 == '\0') {
      FUN_00852020(piVar2[2]);
      piVar3 = (int *)*piVar2;
      FUN_0089120c(piVar2);
      piVar2 = piVar3;
      cVar1 = *(char *)((int)piVar3 + 0x11);
    }
    *(int *)(*(int *)(in_ECX + 0xe8) + 4) = *(int *)(in_ECX + 0xe8);
    *(undefined4 *)*(undefined4 *)(in_ECX + 0xe8) = *(undefined4 *)(in_ECX + 0xe8);
    *(int *)(*(int *)(in_ECX + 0xe8) + 8) = *(int *)(in_ECX + 0xe8);
    *(undefined4 *)(in_ECX + 0xec) = 0;
    uVar4 = *(undefined4 *)(in_ECX + 0xe8);
    *(undefined4 *)(in_ECX + 0xe8) = *(undefined4 *)(iVar6 + 4);
    *(undefined4 *)(iVar6 + 4) = uVar4;
    uVar4 = *(undefined4 *)(in_ECX + 0xec);
    *(undefined4 *)(in_ECX + 0xec) = *(undefined4 *)(iVar6 + 8);
    *(undefined4 *)(iVar6 + 8) = uVar4;
  }
  uStack_c = 1;
  FUN_004ca160(*puStack_24,puStack_24);
  uStack_c = 0xffffffff;
  FUN_0089120c(puStack_24);
  FUN_005083a0(DAT_00fe18f8,&iStack_38);
  uStack_c = 2;
  uVar7 = 0;
  uVar8 = iStack_34 - iStack_38 >> 2;
  *(undefined4 *)(in_ECX + 0xe0) = 0;
  if (uVar8 != 0) {
    do {
      FUN_006bc1a0(in_ECX,*(undefined4 *)(iStack_38 + uVar7 * 4),1);
      uVar7 = uVar7 + 1;
    } while (uVar7 < uVar8);
  }
  FUN_00757710();
  (**(code **)(**(int **)(in_ECX + 0x84) + 200))();
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    uStack_c._0_1_ = 3;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    uStack_c = CONCAT31(uStack_c._1_3_,2);
  }
  if (DAT_00f9392c == 1) {
    (**(code **)(**(int **)(in_ECX + 0xd4) + 0x16c))(0);
    (**(code **)(**(int **)(in_ECX + 0x8c) + 0x90))(0);
  }
  FUN_006bc330(in_ECX);
  if (iStack_38 != 0) {
    FUN_0089120c(iStack_38);
  }
  ExceptionList = local_14;
  return;
}

