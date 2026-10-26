
void FUN_00432d60(void)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  undefined1 auStack_88 [12];
  undefined4 uStack_7c;
  uint *puStack_78;
  undefined4 uStack_74;
  undefined1 auStack_5c [4];
  undefined1 *puStack_58;
  undefined1 local_54 [20];
  uint local_40;
  uint auStack_38 [4];
  undefined4 uStack_28;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00941b7e;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_5c;
  ExceptionList = &local_14;
  FUN_007459c0();
  iVar2 = in_ECX;
  if ((*(byte *)(in_ECX + 0x28) & 0x10) == 0) {
    if (*(int *)(in_ECX + 0x60) == 0) goto LAB_00432dd4;
    iVar2 = FUN_00745c20();
  }
  if ((((iVar2 != 0) && (*(int *)(iVar2 + 0x60) != 0)) &&
      ((*(uint *)(iVar2 + 0x28) >> 0xc & 1) == 0)) && (*(int *)(iVar2 + 0x60) != 0)) {
    uStack_74 = 0x432dd4;
    FUN_0074a010();
  }
LAB_00432dd4:
  iVar2 = DAT_00fb7618;
  uStack_74 = 0x432de9;
  FUN_006caaf0();
  uStack_74 = *(undefined4 *)(iVar2 + 0x3a);
  puStack_78 = (uint *)local_54;
  uStack_7c = 0x432dfb;
  FUN_00433f80();
  local_c = 0;
  uStack_74 = 0x432e18;
  FUN_00757800();
  local_c = 0xffffffff;
  if (7 < local_40) {
    uStack_74 = 0x432e31;
    FUN_0089120c();
  }
  (**(code **)(**(int **)(in_ECX + 0xf4) + 200))();
  puStack_58 = auStack_88;
  FUN_00433f80(auStack_88,*(int *)(iVar2 + 0x56),*(int *)(iVar2 + 0x56) >> 0x1f);
  FUN_00424c80(&DAT_00bf7508);
  local_c = 1;
  uStack_74 = 0x432e87;
  FUN_00757800();
  local_c = 0xffffffff;
  if (7 < local_40) {
    uStack_74 = 0x432ea0;
    FUN_0089120c();
  }
  (**(code **)(**(int **)(in_ECX + 0xf8) + 200))();
  uVar1 = *(uint *)(iVar2 + 0x56);
  puStack_58 = auStack_88;
  FUN_00433f80(auStack_88,uVar1 + *(uint *)(iVar2 + 0x3a),
               ((int)uVar1 >> 0x1f) + *(int *)(iVar2 + 0x3e) +
               (uint)CARRY4(uVar1,*(uint *)(iVar2 + 0x3a)));
  FUN_00424c80(&DAT_00bf7508);
  local_c = 2;
  uStack_74 = 0x432efc;
  FUN_00757800();
  local_c = 0xffffffff;
  if (7 < local_40) {
    uStack_74 = 0x432f15;
    FUN_0089120c();
  }
  (**(code **)(**(int **)(in_ECX + 0xfc) + 200))();
  FUN_00420070();
  local_c = 3;
  uStack_74 = 0x432f53;
  FUN_00757800();
  local_c = 0xffffffff;
  if (7 < local_40) {
    uStack_74 = 0x432f6c;
    FUN_0089120c();
  }
  (**(code **)(**(int **)(in_ECX + 0x100) + 200))();
  FUN_004330b0();
  local_c = 4;
  uStack_74 = 0x432fab;
  FUN_00757800();
  local_c = 0xffffffff;
  if (7 < local_40) {
    uStack_74 = 0x432fc4;
    FUN_0089120c();
  }
  (**(code **)(**(int **)(in_ECX + 0x108) + 200))();
  uStack_74 = *(undefined4 *)(iVar2 + 0x42);
  puStack_78 = auStack_38;
  uStack_7c = 0x432fe9;
  FUN_00433f80();
  local_c = 5;
  uStack_74 = 0x433006;
  FUN_00757800();
  local_c = 0xffffffff;
  if (7 < uStack_24) {
    uStack_74 = 0x43301f;
    FUN_0089120c();
  }
  auStack_38[0] = auStack_38[0] & 0xffff0000;
  uStack_24 = 7;
  uStack_28 = 0;
  (**(code **)(**(int **)(in_ECX + 0x104) + 200))();
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 6;
    FUN_004e1590();
    uStack_74 = 0x433072;
    _atexit((_func_4879 *)&LAB_00bccc80);
    DAT_00f942ca = *(undefined2 *)(iVar2 + 0x4c);
  }
  else {
    DAT_00f942ca = *(undefined2 *)(iVar2 + 0x4c);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_5c);
  return;
}

