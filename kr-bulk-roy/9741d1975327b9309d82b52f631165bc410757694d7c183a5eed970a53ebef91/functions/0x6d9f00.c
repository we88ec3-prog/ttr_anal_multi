
void FUN_006d9f00(void)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar4;
  int *piVar5;
  LPCRITICAL_SECTION local_44;
  LPCRITICAL_SECTION p_Stack_40;
  int local_3c;
  uint uStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c._0_1_ = 0xff;
  uStack_c._1_3_ = 0xffffff;
  puStack_10 = &LAB_00919a5c;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_44;
  ExceptionList = &local_14;
  local_3c = in_ECX;
  if (*(char *)(in_ECX + 0x24) != '\0') {
    piVar4 = *(int **)(in_ECX + 0x34);
    if (*(char *)(in_ECX + 0x25) == '\0') {
      if (piVar4 != (int *)0x0) {
        (**(code **)(*piVar4 + 0x48))
                  (*(undefined4 *)(in_ECX + 0xa4),DAT_00d61f20 ^ (uint)&stack0xffffffb0);
      }
      if (*(int *)(in_ECX + 0x6c) != 0) {
        iVar2 = FUN_00444ad0();
        sVar1 = *(short *)(iVar2 + 0x286);
        iVar2 = FUN_00444ad0();
        p_Stack_40 = (LPCRITICAL_SECTION)(int)sVar1;
        local_44 = *(LPCRITICAL_SECTION *)(iVar2 + 0x30c);
        iVar2 = **(int **)(local_3c + 0x6c);
        uVar3 = FUN_008fed10();
        (**(code **)(iVar2 + 0x48))(uVar3);
      }
      uStack_24 = 0xf;
      uStack_28 = 0;
      uStack_38 = uStack_38 & 0xffffff00;
      FUN_0040b310("Character");
      uStack_c._1_3_ = 0;
      if ((DAT_00fb8828 & 1) == 0) {
        DAT_00fb8828 = DAT_00fb8828 | 1;
        uStack_c._0_1_ = 0x10;
        uStack_c._1_3_ = 0;
        FUN_0054f850();
        _atexit((_func_4879 *)&LAB_00bcd580);
      }
      local_44 = DAT_00fb9234;
      if ((DAT_00fb8828 & 1) == 0) {
        DAT_00fb8828 = DAT_00fb8828 | 1;
        uStack_c._0_1_ = 0x11;
        FUN_0054f850();
        _atexit((_func_4879 *)&LAB_00bcd580);
      }
      p_Stack_40 = DAT_00fb935c;
      if ((DAT_00fab0d4 & 1) == 0) {
        DAT_00fab0d4 = DAT_00fab0d4 | 1;
        uStack_c._0_1_ = 0x12;
        FUN_0080a3a0();
        _atexit((_func_4879 *)&LAB_00bccdd0);
      }
      uStack_c._0_1_ = 0xf;
      local_44 = (LPCRITICAL_SECTION)((float)local_44 * (float)p_Stack_40);
      iVar2 = FUN_0080c040(&DAT_00fab028);
      *(uint *)(iVar2 + 0x20) = *(uint *)(iVar2 + 0x20) | 1;
      *(LPCRITICAL_SECTION *)(iVar2 + 0x24) = local_44;
      if ((DAT_00fab0d4 & 1) == 0) {
        DAT_00fab0d4 = DAT_00fab0d4 | 1;
        uStack_c._0_1_ = 0x13;
        FUN_0080a3a0();
        _atexit((_func_4879 *)&LAB_00bccdd0);
        uStack_c._0_1_ = 0xf;
      }
      FUN_0080c0a0();
      uStack_c = 0xffffffff;
      if (0xf < uStack_24) {
        FUN_0089120c(uStack_38);
      }
      uStack_24 = 0xf;
      uStack_28 = 0;
      uStack_38 = uStack_38 & 0xffffff00;
      FUN_0040b310("Battle");
      uStack_c._1_3_ = 0;
      if ((DAT_00fb8828 & 1) == 0) {
        DAT_00fb8828 = DAT_00fb8828 | 1;
        uStack_c._0_1_ = 0x15;
        uStack_c._1_3_ = 0;
        FUN_0054f850();
        _atexit((_func_4879 *)&LAB_00bcd580);
      }
      local_44 = DAT_00fb9234;
      if ((DAT_00fb8828 & 1) == 0) {
        DAT_00fb8828 = DAT_00fb8828 | 1;
        uStack_c._0_1_ = 0x16;
        FUN_0054f850();
        _atexit((_func_4879 *)&LAB_00bcd580);
      }
      p_Stack_40 = DAT_00fb935c;
      if ((DAT_00fab0d4 & 1) == 0) {
        DAT_00fab0d4 = DAT_00fab0d4 | 1;
        uStack_c._0_1_ = 0x17;
        FUN_0080a3a0();
        _atexit((_func_4879 *)&LAB_00bccdd0);
      }
      uStack_c._0_1_ = 0x14;
      local_44 = (LPCRITICAL_SECTION)((float)local_44 * 0.57 * (float)p_Stack_40);
      iVar2 = FUN_0080c040(&DAT_00fab028);
      *(uint *)(iVar2 + 0x20) = *(uint *)(iVar2 + 0x20) | 1;
      *(LPCRITICAL_SECTION *)(iVar2 + 0x24) = local_44;
      if ((DAT_00fab0d4 & 1) == 0) {
        DAT_00fab0d4 = DAT_00fab0d4 | 1;
        uStack_c._0_1_ = 0x18;
        FUN_0080a3a0();
        _atexit((_func_4879 *)&LAB_00bccdd0);
        uStack_c._0_1_ = 0x14;
      }
      FUN_0080c0a0();
      uStack_c = 0xffffffff;
      if (0xf < uStack_24) {
        FUN_0089120c(uStack_38);
      }
      uStack_24 = 0xf;
      uStack_28 = 0;
      uStack_38 = uStack_38 & 0xffffff00;
      FUN_0040b310("Damage");
      uStack_c._1_3_ = 0;
      if ((DAT_00fb8828 & 1) == 0) {
        DAT_00fb8828 = DAT_00fb8828 | 1;
        uStack_c._0_1_ = 0x1a;
        uStack_c._1_3_ = 0;
        FUN_0054f850();
        _atexit((_func_4879 *)&LAB_00bcd580);
      }
      local_44 = DAT_00fb9234;
      if ((DAT_00fb8828 & 1) == 0) {
        DAT_00fb8828 = DAT_00fb8828 | 1;
        uStack_c._0_1_ = 0x1b;
        FUN_0054f850();
        _atexit((_func_4879 *)&LAB_00bcd580);
      }
      p_Stack_40 = DAT_00fb935c;
      if ((DAT_00fab0d4 & 1) == 0) {
        DAT_00fab0d4 = DAT_00fab0d4 | 1;
        uStack_c._0_1_ = 0x1c;
        FUN_0080a3a0();
        _atexit((_func_4879 *)&LAB_00bccdd0);
      }
      uStack_c._0_1_ = 0x19;
      local_44 = (LPCRITICAL_SECTION)((float)local_44 * 0.714 * (float)p_Stack_40);
      iVar2 = FUN_0080c040(&DAT_00fab028);
      *(uint *)(iVar2 + 0x20) = *(uint *)(iVar2 + 0x20) | 1;
      *(LPCRITICAL_SECTION *)(iVar2 + 0x24) = local_44;
      if ((DAT_00fab0d4 & 1) == 0) {
        DAT_00fab0d4 = DAT_00fab0d4 | 1;
        uStack_c._0_1_ = 0x1d;
        FUN_0080a3a0();
        _atexit((_func_4879 *)&LAB_00bccdd0);
        uStack_c._0_1_ = 0x19;
      }
      FUN_0080c0a0();
      uStack_c = 0xffffffff;
      if (0xf < uStack_24) {
        FUN_0089120c(uStack_38);
      }
      uStack_24 = 0xf;
      uStack_28 = 0;
      uStack_38 = uStack_38 & 0xffffff00;
      FUN_0040b310(&DAT_00c05800);
      uStack_c._1_3_ = 0;
      if ((DAT_00fb8828 & 1) == 0) {
        DAT_00fb8828 = DAT_00fb8828 | 1;
        uStack_c._0_1_ = 0x1f;
        uStack_c._1_3_ = 0;
        FUN_0054f850();
        _atexit((_func_4879 *)&LAB_00bcd580);
      }
      local_44 = DAT_00fb924c;
      if ((DAT_00fb8828 & 1) == 0) {
        DAT_00fb8828 = DAT_00fb8828 | 1;
        uStack_c._0_1_ = 0x20;
        FUN_0054f850();
        _atexit((_func_4879 *)&LAB_00bcd580);
      }
      p_Stack_40 = DAT_00fb935c;
      if ((DAT_00fab0d4 & 1) == 0) {
        DAT_00fab0d4 = DAT_00fab0d4 | 1;
        uStack_c._0_1_ = 0x21;
        FUN_0080a3a0();
        _atexit((_func_4879 *)&LAB_00bccdd0);
      }
      uStack_c._0_1_ = 0x1e;
      local_44 = (LPCRITICAL_SECTION)((float)local_44 * (float)p_Stack_40);
      iVar2 = FUN_0080c040(&DAT_00fab028);
      *(uint *)(iVar2 + 0x20) = *(uint *)(iVar2 + 0x20) | 1;
      *(LPCRITICAL_SECTION *)(iVar2 + 0x24) = local_44;
      if ((DAT_00fab0d4 & 1) == 0) {
        DAT_00fab0d4 = DAT_00fab0d4 | 1;
        uStack_c._0_1_ = 0x22;
        FUN_0080a3a0();
        _atexit((_func_4879 *)&LAB_00bccdd0);
        uStack_c._0_1_ = 0x1e;
      }
      FUN_0080c0a0();
      uStack_c = 0xffffffff;
      if (0xf < uStack_24) {
        FUN_0089120c(uStack_38);
      }
      uStack_24 = 0xf;
      uStack_28 = 0;
      uStack_38 = uStack_38 & 0xffffff00;
      FUN_0040b310("Voice");
      uStack_c._1_3_ = 0;
      if ((DAT_00fb8828 & 1) == 0) {
        DAT_00fb8828 = DAT_00fb8828 | 1;
        uStack_c = 0x24;
        FUN_0054f850();
        _atexit((_func_4879 *)&LAB_00bcd580);
      }
      p_Stack_40 = (LPCRITICAL_SECTION)DAT_00fb9264;
      if ((DAT_00fb8828 & 1) == 0) {
        DAT_00fb8828 = DAT_00fb8828 | 1;
        uStack_c._0_1_ = 0x25;
        FUN_0054f850();
        _atexit((_func_4879 *)&LAB_00bcd580);
      }
      local_44 = DAT_00fb935c;
      if ((DAT_00fab0d4 & 1) == 0) {
        DAT_00fab0d4 = DAT_00fab0d4 | 1;
        uStack_c._0_1_ = 0x26;
        FUN_0080a3a0();
        _atexit((_func_4879 *)&LAB_00bccdd0);
      }
      uStack_c._0_1_ = 0x23;
      local_44 = (LPCRITICAL_SECTION)((float)local_44 * (float)p_Stack_40);
      iVar2 = FUN_0080c040(&DAT_00fab028);
      *(uint *)(iVar2 + 0x20) = *(uint *)(iVar2 + 0x20) | 1;
      *(LPCRITICAL_SECTION *)(iVar2 + 0x24) = local_44;
      if ((DAT_00fab0d4 & 1) == 0) {
        DAT_00fab0d4 = DAT_00fab0d4 | 1;
        uStack_c._0_1_ = 0x27;
        FUN_0080a3a0();
        _atexit((_func_4879 *)&LAB_00bccdd0);
        uStack_c._0_1_ = 0x23;
      }
    }
    else {
      if (piVar4 != (int *)0x0) {
        (**(code **)(*piVar4 + 0x48))(0);
        *(undefined4 *)(in_ECX + 0x68) = 0;
        *(undefined4 *)(in_ECX + 0x60) = 0;
      }
      if (*(int **)(in_ECX + 0x6c) != (int *)0x0) {
        (**(code **)(**(int **)(in_ECX + 0x6c) + 0x48))(0);
        *(undefined4 *)(in_ECX + 0xa0) = 0;
        *(undefined4 *)(in_ECX + 0x98) = 0;
      }
      uStack_24 = 0xf;
      uStack_28 = 0;
      uStack_38 = uStack_38 & 0xffffff00;
      FUN_0040b310("Character");
      uStack_c._1_3_ = 0;
      if ((DAT_00fab0d4 & 1) == 0) {
        DAT_00fab0d4 = DAT_00fab0d4 | 1;
        uStack_c._0_1_ = 1;
        uStack_c._1_3_ = 0;
        FUN_0080a3a0();
        _atexit((_func_4879 *)&LAB_00bccdd0);
      }
      uStack_c._0_1_ = 0;
      iVar2 = FUN_0080c040(&DAT_00fab028);
      *(uint *)(iVar2 + 0x20) = *(uint *)(iVar2 + 0x20) | 1;
      *(undefined4 *)(iVar2 + 0x24) = 0;
      if ((DAT_00fab0d4 & 1) == 0) {
        DAT_00fab0d4 = DAT_00fab0d4 | 1;
        uStack_c._0_1_ = 2;
        FUN_0080a3a0();
        _atexit((_func_4879 *)&LAB_00bccdd0);
        uStack_c._0_1_ = 0;
      }
      FUN_0080c0a0();
      uStack_c = 0xffffffff;
      if (0xf < uStack_24) {
        FUN_0089120c(uStack_38);
      }
      uStack_24 = 0xf;
      uStack_28 = 0;
      uStack_38 = uStack_38 & 0xffffff00;
      FUN_0040b310("Battle");
      uStack_c._1_3_ = 0;
      if ((DAT_00fab0d4 & 1) == 0) {
        DAT_00fab0d4 = DAT_00fab0d4 | 1;
        uStack_c._0_1_ = 4;
        uStack_c._1_3_ = 0;
        FUN_0080a3a0();
        _atexit((_func_4879 *)&LAB_00bccdd0);
      }
      uStack_c._0_1_ = 3;
      iVar2 = FUN_0080c040(&DAT_00fab028);
      *(uint *)(iVar2 + 0x20) = *(uint *)(iVar2 + 0x20) | 1;
      *(undefined4 *)(iVar2 + 0x24) = 0;
      if ((DAT_00fab0d4 & 1) == 0) {
        DAT_00fab0d4 = DAT_00fab0d4 | 1;
        uStack_c._0_1_ = 5;
        FUN_0080a3a0();
        _atexit((_func_4879 *)&LAB_00bccdd0);
        uStack_c._0_1_ = 3;
      }
      FUN_0080c0a0();
      uStack_c = 0xffffffff;
      if (0xf < uStack_24) {
        FUN_0089120c(uStack_38);
      }
      uStack_24 = 0xf;
      uStack_28 = 0;
      uStack_38 = uStack_38 & 0xffffff00;
      FUN_0040b310("Damage");
      uStack_c._1_3_ = 0;
      if ((DAT_00fab0d4 & 1) == 0) {
        DAT_00fab0d4 = DAT_00fab0d4 | 1;
        uStack_c._0_1_ = 7;
        uStack_c._1_3_ = 0;
        FUN_0080a3a0();
        _atexit((_func_4879 *)&LAB_00bccdd0);
      }
      uStack_c._0_1_ = 6;
      iVar2 = FUN_0080c040(&DAT_00fab028);
      *(uint *)(iVar2 + 0x20) = *(uint *)(iVar2 + 0x20) | 1;
      *(undefined4 *)(iVar2 + 0x24) = 0;
      if ((DAT_00fab0d4 & 1) == 0) {
        DAT_00fab0d4 = DAT_00fab0d4 | 1;
        uStack_c._0_1_ = 8;
        FUN_0080a3a0();
        _atexit((_func_4879 *)&LAB_00bccdd0);
        uStack_c._0_1_ = 6;
      }
      FUN_0080c0a0();
      uStack_c = 0xffffffff;
      if (0xf < uStack_24) {
        FUN_0089120c(uStack_38);
      }
      uStack_24 = 0xf;
      uStack_28 = 0;
      uStack_38 = uStack_38 & 0xffffff00;
      FUN_0040b310(&DAT_00c05800);
      uStack_c._1_3_ = 0;
      if ((DAT_00fab0d4 & 1) == 0) {
        DAT_00fab0d4 = DAT_00fab0d4 | 1;
        uStack_c._0_1_ = 10;
        uStack_c._1_3_ = 0;
        FUN_0080a3a0();
        _atexit((_func_4879 *)&LAB_00bccdd0);
      }
      uStack_c._0_1_ = 9;
      iVar2 = FUN_0080c040(&DAT_00fab028);
      *(uint *)(iVar2 + 0x20) = *(uint *)(iVar2 + 0x20) | 1;
      *(undefined4 *)(iVar2 + 0x24) = 0;
      if ((DAT_00fab0d4 & 1) == 0) {
        DAT_00fab0d4 = DAT_00fab0d4 | 1;
        uStack_c._0_1_ = 0xb;
        FUN_0080a3a0();
        _atexit((_func_4879 *)&LAB_00bccdd0);
        uStack_c._0_1_ = 9;
      }
      FUN_0080c0a0();
      uStack_c = 0xffffffff;
      if (0xf < uStack_24) {
        FUN_0089120c(uStack_38);
      }
      uStack_24 = 0xf;
      uStack_28 = 0;
      uStack_38 = uStack_38 & 0xffffff00;
      FUN_0040b310("Voice");
      uStack_c._1_3_ = 0;
      if ((DAT_00fab0d4 & 1) == 0) {
        DAT_00fab0d4 = DAT_00fab0d4 | 1;
        uStack_c._0_1_ = 0xd;
        uStack_c._1_3_ = 0;
        FUN_0080a3a0();
        _atexit((_func_4879 *)&LAB_00bccdd0);
      }
      uStack_c._0_1_ = 0xc;
      iVar2 = FUN_0080c040(&DAT_00fab028);
      *(uint *)(iVar2 + 0x20) = *(uint *)(iVar2 + 0x20) | 1;
      *(undefined4 *)(iVar2 + 0x24) = 0;
      if ((DAT_00fab0d4 & 1) == 0) {
        DAT_00fab0d4 = DAT_00fab0d4 | 1;
        uStack_c._0_1_ = 0xe;
        FUN_0080a3a0();
        _atexit((_func_4879 *)&LAB_00bccdd0);
        uStack_c._0_1_ = 0xc;
      }
    }
    FUN_0080c0a0();
    if (0xf < uStack_24) {
      FUN_0089120c(uStack_38);
    }
    *(undefined1 *)(local_3c + 0x24) = 0;
  }
  lpCriticalSection = (LPCRITICAL_SECTION)(local_3c + 0xb4);
  local_44 = lpCriticalSection;
  EnterCriticalSection(lpCriticalSection);
  uStack_c = 0x28;
  piVar4 = (int *)**(int **)(local_3c + 0x28);
  if (piVar4 != *(int **)(local_3c + 0x28)) {
    do {
      if (piVar4[0xc] == 2) {
        if ((int *)piVar4[2] != (int *)0x0) {
          (**(code **)(*(int *)piVar4[2] + 0x2c))();
        }
        piVar5 = (int *)*piVar4;
        if (piVar4 != *(int **)(local_3c + 0x28)) {
          *(int **)piVar4[1] = piVar5;
          *(int *)(*piVar4 + 4) = piVar4[1];
          if (0xf < (uint)piVar4[8]) {
            FUN_0089120c(piVar4[3]);
          }
          piVar4[8] = 0xf;
          piVar4[7] = 0;
          *(undefined1 *)(piVar4 + 3) = 0;
          FUN_0089120c(piVar4);
          *(int *)(local_3c + 0x2c) = *(int *)(local_3c + 0x2c) + -1;
        }
      }
      else {
        piVar5 = (int *)*piVar4;
      }
      lpCriticalSection = local_44;
      piVar4 = piVar5;
    } while (piVar5 != *(int **)(local_3c + 0x28));
  }
  LeaveCriticalSection(lpCriticalSection);
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_44);
  return;
}

