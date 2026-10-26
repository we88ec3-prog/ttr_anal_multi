
void FUN_0049cc90(void)

{
  ushort uVar1;
  undefined4 uVar2;
  uint uVar3;
  int *in_ECX;
  undefined4 uVar4;
  undefined4 uVar5;
  int local_58;
  int local_54;
  char *local_4c;
  undefined4 local_48;
  char *local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined **local_34 [3];
  undefined1 local_28 [12];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00936f76;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_58;
  ExceptionList = &local_14;
  if ((in_ECX != (int *)0x0) && (*(int *)(in_ECX[0x56] + 8) != 3)) {
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c = 0;
      FUN_0054f850(DAT_00d61f20 ^ (uint)&stack0xffffffa0);
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    local_c = 0xffffffff;
    FUN_0040f060();
    local_54 = 0;
    local_58 = FUN_00891268(0xc);
    if (local_58 == 0) {
      local_4c = (char *)0x0;
      std::exception::exception((exception *)local_34,&local_4c);
      local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_34,&DAT_00c857a8);
    }
    *(int *)local_58 = local_58;
    *(int *)(local_58 + 4) = local_58;
    local_c = 1;
    FUN_0049ce10(&local_58,0);
    if (local_54 != 0) {
      uVar1 = *(ushort *)(in_ECX + 1);
      uVar5 = 0x3f800000;
      uVar4 = 0;
      local_48 = 2;
      local_44 = "GETITEM";
      local_40 = 0xffffffff;
      local_3c = 0xffffffff;
      local_38 = 0;
      uVar2 = (**(code **)(*in_ECX + 0x50))(local_28,0,0x3f800000);
      uVar3 = (uint)uVar1;
      FUN_0049b140(uVar3,uVar2);
      FUN_00551f20(uVar3,uVar2,uVar4,uVar5);
    }
    FUN_0049d010();
    FUN_0056fb00();
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_58);
  return;
}

