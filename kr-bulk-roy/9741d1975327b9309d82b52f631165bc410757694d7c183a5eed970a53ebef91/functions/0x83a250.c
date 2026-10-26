
/* WARNING: Removing unreachable block (ram,0x0083a45b) */
/* WARNING: Removing unreachable block (ram,0x0083a483) */
/* WARNING: Removing unreachable block (ram,0x0083a497) */
/* WARNING: Removing unreachable block (ram,0x0083a4a1) */
/* WARNING: Removing unreachable block (ram,0x0083a4b6) */
/* WARNING: Removing unreachable block (ram,0x0083a4cc) */
/* WARNING: Removing unreachable block (ram,0x0083a4d2) */
/* WARNING: Removing unreachable block (ram,0x0083a4e0) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0083a250(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  int *piVar3;
  uint uVar4;
  undefined4 uStack_ec;
  uint uStack_e8;
  int iStack_a8;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  uint local_28;
  undefined4 local_24;
  void *pvStack_20;
  uint local_1c;
  undefined4 uStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00918369;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&uStack_ec;
  ExceptionList = &local_14;
  local_28 = 0;
  local_2c = 0;
  local_30 = 0;
  local_34 = 0;
  local_3c = 0;
  local_40 = 0;
  local_44 = 0;
  DAT_00fba930 = 0;
  local_48 = 0;
  local_50 = 0;
  local_54 = 0;
  local_58 = 0;
  local_5c = 0;
  local_24 = 0x3f800000;
  local_38 = 0x3f800000;
  local_4c = 0x3f800000;
  local_60 = 0x3f800000;
  (**(code **)(*(int *)in_ECX[0x3b] + 0xb0))
            ((int *)in_ECX[0x3b],0x100,&local_60,DAT_00d61f20 ^ (uint)&stack0xffffff08);
  if (in_ECX[0xb3] != 0) {
    (**(code **)(*(int *)in_ECX[0xb3] + 0x14))((int *)in_ECX[0xb3]);
  }
  if (DAT_00fe34d8 == (undefined *)0x0) {
    if ((DAT_00fe3480 & 1) == 0) {
      DAT_00fe3480 = DAT_00fe3480 | 1;
      uStack_18 = 0;
      FUN_00862d10();
      _atexit((_func_4879 *)&LAB_00bd0e20);
      uStack_18 = 0xffffffff;
    }
    DAT_00fe34d8 = &DAT_00fe3488;
  }
  FUN_00862f50();
  if (in_ECX[0xfd] == 0) {
    FUN_0083d8e0();
  }
  else {
    iVar1 = FUN_0083ff20(in_ECX + 0x51,*(undefined4 *)(in_ECX[0xfd] + 0x16c));
    if (iVar1 != 0) {
      FUN_008392d0();
      uStack_18 = 1;
      iStack_a8 = in_ECX[0xfd];
      FUN_0085aa60(iVar1,in_ECX);
      piVar3 = in_ECX;
      uVar2 = FUN_0083eef0();
      FUN_00862fb0(uVar2,piVar3);
      uStack_18 = 0xffffffff;
      FUN_00839400();
    }
  }
  if (param_1 != 0) {
    uStack_e8 = (**(code **)(*in_ECX + 0x88))();
    uVar4 = 0;
    if (uStack_e8 != 0) {
      do {
        uStack_ec = 0;
        (**(code **)(*in_ECX + 0x8c))(uVar4,&uStack_ec,&stack0xffffff10);
        uVar4 = uVar4 + 1;
      } while (uVar4 < uStack_e8);
    }
    (**(code **)(*in_ECX + 8))();
  }
  if (param_3 != 0) {
    FUN_00849a90(in_ECX);
  }
  if (param_2 != 0) {
    (**(code **)(*in_ECX + 4))();
  }
  _DAT_00fbacbc = 0;
  _DAT_00fba934 = 0;
  _DAT_00fba938 = 0;
  in_ECX[0x102] = 0;
  if ((uint)in_ECX[0x103] < 0x10) {
    *(undefined1 *)(in_ECX + 0xfe) = 0;
  }
  else {
    *(undefined1 *)in_ECX[0xfe] = 0;
  }
  ExceptionList = pvStack_20;
  __security_check_cookie(local_28 ^ (uint)&stack0xffffff08);
  return;
}

