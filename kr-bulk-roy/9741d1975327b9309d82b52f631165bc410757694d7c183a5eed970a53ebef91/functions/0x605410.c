
void FUN_00605410(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  uint *puVar3;
  int unaff_EDI;
  undefined4 *puVar4;
  uint uVar5;
  uint local_6c;
  uint local_68;
  int local_60;
  int local_5c;
  uint local_58;
  undefined4 uStack_48;
  uint uStack_44;
  uint uStack_24;
  undefined4 uStack_20;
  void *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009432b0;
  local_14 = ExceptionList;
  local_1c = (void *)(DAT_00d61f20 ^ (uint)&local_6c);
  ExceptionList = &local_14;
  local_68 = 1;
  puVar4 = (undefined4 *)(in_ECX + 0x124);
  puVar3 = &DAT_00fc7bcc;
  local_60 = in_ECX;
  do {
    uVar5 = local_68;
    if ((DAT_00fc1cbc & 1) == 0) {
      DAT_00fc1cbc = DAT_00fc1cbc | 1;
      local_c = 0;
      FUN_004fdac0();
      _atexit(FUN_00bce150);
      local_c = 0xffffffff;
    }
    local_6c = uVar5 / 7;
    if (((local_6c == 0) && (puVar3 != (uint *)0x1c)) && (puVar3[-7] != 0)) {
      if ((DAT_00f8d9a4 & 1) == 0) {
        DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
        local_c = 1;
        FUN_0051c120();
        _atexit((_func_4879 *)&LAB_00bccc90);
        local_c = 0xffffffff;
      }
      local_58 = *puVar3;
      FUN_008438c0();
      if ((local_5c == DAT_00f8d91c) || (iVar1 = *(int *)(local_5c + 0x10), iVar1 == 0))
      goto LAB_0060556a;
      uVar5 = puVar3[-1];
      (**(code **)(*(int *)puVar4[-8] + 0x1ac))
                (*(undefined4 *)(iVar1 + 0x20),*puVar3,puVar3[-3],puVar3[-2]);
      FUN_00605900(puVar3 + -7,iVar1);
    }
    else {
LAB_0060556a:
      FUN_00757710();
      uVar5 = 0;
      (**(code **)(*(int *)puVar4[-8] + 0x1ac))(0xffffffff,0xffffffff,0,0);
    }
    (**(code **)(*(int *)puVar4[-8] + 200))();
    if ((DAT_00fc1cbc & 1) == 0) {
      DAT_00fc1cbc = DAT_00fc1cbc | 1;
      uStack_20 = 2;
      FUN_004fdac0();
      _atexit(FUN_00bce150);
      uStack_20 = 0xffffffff;
    }
    if (((uVar5 == 0) && (puVar3 + 0x69 != (uint *)0x0)) && (puVar3[0x69] != 0)) {
      if ((DAT_00f8d9a4 & 1) == 0) {
        DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
        uStack_20 = 3;
        FUN_0051c120();
        _atexit((_func_4879 *)&LAB_00bccc90);
        uStack_20 = 0xffffffff;
      }
      FUN_008438c0(&stack0xffffff80);
      if ((unaff_EDI == DAT_00f8d91c) || (iVar1 = *(int *)(unaff_EDI + 0x10), iVar1 == 0))
      goto LAB_00605694;
      (**(code **)(*(int *)*puVar4 + 0x1ac))
                (*(undefined4 *)(iVar1 + 0x20),puVar3[0x70],puVar3[0x6d],puVar3[0x6e],puVar3[0x6f]);
      FUN_00605900(puVar3 + 0x69,iVar1);
    }
    else {
LAB_00605694:
      FUN_00757710();
      (**(code **)(*(int *)*puVar4 + 0x1ac))(0xffffffff,0xffffffff,0,0,0);
    }
    (**(code **)(*(int *)*puVar4 + 200))();
    local_68 = local_68 + 1;
    puVar3 = puVar3 + 0x10;
    puVar4 = puVar4 + 1;
    if (0xfc7d4b < (int)puVar3) {
      if ((DAT_00fc1cbc & 1) == 0) {
        DAT_00fc1cbc = DAT_00fc1cbc | 1;
        local_c = 4;
        FUN_004fdac0();
        _atexit(FUN_00bce150);
        local_c = 0xffffffff;
      }
      FUN_004068f0();
      local_c = 5;
      iVar1 = *(int *)(local_60 + 0x18c);
      if (*(char *)(iVar1 + 0x141) == '\0') {
        FUN_00757710();
      }
      else {
        FUN_006edb10();
      }
      *(undefined4 *)(iVar1 + 0x168) = 0;
      *(undefined4 *)(iVar1 + 0x160) = 0;
      *(undefined4 *)(iVar1 + 0x164) = 0;
      *(undefined4 *)(iVar1 + 0x14c) = 0;
      local_c = 0xffffffff;
      if (7 < uStack_24) {
        FUN_0089120c();
      }
      (**(code **)(**(int **)(local_60 + 0x18c) + 200))();
      if ((DAT_00fc1cbc & 1) == 0) {
        DAT_00fc1cbc = DAT_00fc1cbc | 1;
        local_c = 6;
        FUN_004fdac0();
        _atexit(FUN_00bce150);
        local_c = 0xffffffff;
      }
      (**(code **)(**(int **)(local_60 + 0x17c) + 0x94))();
      if ((DAT_00fc1cbc & 1) == 0) {
        DAT_00fc1cbc = DAT_00fc1cbc | 1;
        puStack_10 = (undefined1 *)0x7;
        FUN_004fdac0();
        _atexit(FUN_00bce150);
        puStack_10 = (undefined1 *)0xffffffff;
      }
      uVar2 = FUN_004068f0();
      puStack_10 = (undefined1 *)0x8;
      FUN_00757800(uVar2);
      puStack_10 = (undefined1 *)0xffffffff;
      if (7 < uStack_44) {
        FUN_0089120c(local_58);
      }
      local_58 = local_58 & 0xffff0000;
      uStack_44 = 7;
      uStack_48 = 0;
      (**(code **)(**(int **)(local_60 + 400) + 200))();
      if ((DAT_00fc1cbc & 1) == 0) {
        DAT_00fc1cbc = DAT_00fc1cbc | 1;
        puStack_10 = (undefined1 *)0x9;
        FUN_004fdac0();
        _atexit(FUN_00bce150);
        puStack_10 = (undefined1 *)0xffffffff;
      }
      (**(code **)(**(int **)(local_60 + 0x180) + 0x94))(DAT_00fc7f00 != 0);
      ExceptionList = local_1c;
      __security_check_cookie(uStack_24 ^ (uint)&stack0xffffff8c);
      return;
    }
  } while( true );
}

