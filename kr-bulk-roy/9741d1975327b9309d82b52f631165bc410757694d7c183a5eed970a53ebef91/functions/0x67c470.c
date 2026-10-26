
void FUN_0067c470(void)

{
  code *pcVar1;
  uint uVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int local_38;
  int local_34;
  undefined4 local_30;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00935c5d;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  FUN_0067bfa0(in_ECX);
  puVar4 = (undefined4 *)(in_ECX + 0xfc);
  puVar5 = (undefined4 *)(in_ECX + 300);
  local_34 = 2;
  do {
    (**(code **)(*(int *)*puVar4 + 0x19c))(puVar5[-1],*puVar5,puVar5[1],puVar5[2],uVar2);
    FUN_005d99d0(*puVar5);
    (**(code **)(*(int *)*puVar4 + 200))();
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 0xe;
    local_34 = local_34 + -1;
  } while (local_34 != 0);
  if ((*(int *)(in_ECX + 400) == 0) || (*(int *)(in_ECX + 0x194) == 0)) {
    (**(code **)(**(int **)(in_ECX + 0xf8) + 0x19c))(0xffffffff,0xffffffff,0,0);
    (**(code **)(**(int **)(in_ECX + 0xf8) + 200))();
    (**(code **)(**(int **)(in_ECX + 0x104) + 0x19c))(0xffffffff,0xffffffff,0,0);
    (**(code **)(**(int **)(in_ECX + 0x104) + 200))();
    FUN_00757710();
    (**(code **)(**(int **)(in_ECX + 0x108) + 200))();
    FUN_00757710();
    (**(code **)(**(int **)(in_ECX + 0x10c) + 200))();
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 4;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 0xffffffff;
    }
    local_38 = 0x1a;
    FUN_005740f0(&local_38);
    if (local_34 == DAT_00fe5ac8) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    uVar3 = FUN_004068f0();
    local_8 = 5;
    FUN_00757800(uVar3);
    local_8 = 0xffffffff;
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
    (**(code **)(**(int **)(in_ECX + 0x110) + 200))();
    (**(code **)(**(int **)(in_ECX + 0xf4) + 0x94))(0);
    (**(code **)(**(int **)(in_ECX + 0x118) + 0x94))(0);
    (**(code **)(**(int **)(in_ECX + 0x114) + 0x90))(0);
  }
  else {
    if ((DAT_00f8d9a8 & 1) == 0) {
      DAT_00f8d9a8 = DAT_00f8d9a8 | 1;
      local_8 = 0;
      FUN_00523540();
      local_8 = CONCAT31(local_8._1_3_,1);
      FUN_00521080(&DAT_00f8d9bc);
      _atexit((_func_4879 *)&LAB_00bccc50);
      local_8 = 0xffffffff;
    }
    local_34 = *(int *)(in_ECX + 0x194);
    FUN_008438c0(&local_34);
    FUN_007597b0(0);
    (**(code **)(**(int **)(in_ECX + 0x118) + 0x94))(1);
    (**(code **)(**(int **)(in_ECX + 0x118) + 200))();
    (**(code **)(**(int **)(in_ECX + 0xf8) + 0x19c))(*(undefined4 *)(in_ECX + 0x194),0xffffffff,0,0)
    ;
    (**(code **)(**(int **)(in_ECX + 0xf8) + 200))();
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 2;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 0xffffffff;
    }
    local_38 = 0x1a;
    FUN_005740f0(&local_38);
    if (local_34 == DAT_00fe5ac8) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    uVar3 = FUN_004068f0();
    local_8 = 3;
    FUN_00757800(uVar3);
    local_8 = 0xffffffff;
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
    (**(code **)(**(int **)(in_ECX + 0x110) + 200))();
    (**(code **)(**(int **)(in_ECX + 0x114) + 0x90))(1);
    (**(code **)(**(int **)(in_ECX + 0x114) + 200))();
  }
  if (((*(int *)(in_ECX + 0x194) == 0) && (*(int *)(*(int *)(in_ECX + 0xfc) + 0x250) != -1)) &&
     (*(int *)(*(int *)(in_ECX + 0x100) + 0x250) != -1)) {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 6;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 0xffffffff;
    }
    local_38 = 0x325;
    FUN_005740f0(&local_38);
    if (local_34 == DAT_00fe5ac8) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    FUN_0067d350();
    FUN_0067cd90(0);
    FUN_0067cd90(1);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

