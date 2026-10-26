
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00509670(int param_1,int param_2,int param_3,undefined4 param_4)

{
  short sVar1;
  code *pcVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  short *psVar7;
  short *psVar8;
  int iVar9;
  int *piVar10;
  undefined **local_6c [3];
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  undefined4 local_48;
  char *local_44;
  int *local_40;
  int local_3c;
  short *local_38;
  char local_31;
  undefined4 local_30;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091e202;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_48 = param_4;
  piVar4 = (int *)(param_1 + 0x2398);
  local_31 = '\0';
  local_54 = 0;
  local_4c = 1;
  local_14 = uVar3;
  do {
    if (((local_4c == 1) && (piVar4 != (int *)0xca0)) && (local_50 = 1, 1 < *piVar4)) {
      piVar10 = piVar4 + -0x31d;
      local_40 = piVar4;
      do {
        iVar9 = local_50;
        if (local_50 - 1U < 100) {
          if (((*piVar10 != 0) && (piVar10[-1] != 0)) &&
             ((piVar10 != (int *)0xc && (piVar10[-2] == param_3)))) {
            local_54 = local_54 + 1;
            if (local_54 == param_2) {
              local_31 = '\x01';
            }
            if ((DAT_00f8d9a4 & 1) == 0) {
              DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
              local_8 = 0;
              FUN_0051c120();
              _atexit((_func_4879 *)&LAB_00bccc90);
              local_8 = 0xffffffff;
            }
            local_38 = (short *)*piVar10;
            FUN_008438c0(&local_38);
            if (local_58 == DAT_00f8d91c) {
              local_38 = (short *)0x0;
            }
            else {
              local_38 = *(short **)(local_58 + 0x10);
            }
            if ((DAT_00fab0d8 & 1) == 0) {
              DAT_00fab0d8 = DAT_00fab0d8 | 1;
              local_8 = 1;
              _DAT_00fab0e4 = 0;
              iVar5 = FUN_00891268(0x28);
              if (iVar5 == 0) {
                local_44 = (char *)0x0;
                std::exception::exception((exception *)local_6c,&local_44);
                local_6c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
                __CxxThrowException_8(local_6c,&DAT_00c857a8);
              }
              DAT_00fab0e0 = iVar5;
              *(int *)iVar5 = iVar5;
              *(int *)(DAT_00fab0e0 + 4) = DAT_00fab0e0;
              *(int *)(DAT_00fab0e0 + 8) = DAT_00fab0e0;
              *(undefined1 *)(DAT_00fab0e0 + 0x20) = 1;
              *(undefined1 *)(DAT_00fab0e0 + 0x21) = 1;
              DAT_00fab0ec = 0;
              _DAT_00fab0f0 = 0;
              _DAT_00fab0f4 = 0;
              _atexit((_func_4879 *)&LAB_00bccdb0);
              local_8 = 0xffffffff;
            }
            local_60 = piVar10[1];
            local_5c = piVar10[2];
            FUN_004dd400(&DAT_00fab0dc,&local_3c,&local_60);
            if ((local_3c != DAT_00fab0e0) && (iVar5 = *(int *)(local_3c + 0x18), iVar5 != 0)) {
              if ((0 < *(int *)(iVar5 + 0x30)) ||
                 (iVar9 = local_50, *(int *)(iVar5 + 0x48) - *(int *)(iVar5 + 0x44) >> 3 != 0)) {
                if (*(int *)(iVar5 + 0x30) == 0) {
                  psVar8 = local_38;
                  if (7 < *(uint *)(local_38 + 10)) {
                    psVar8 = *(short **)local_38;
                  }
                  psVar7 = psVar8;
                  do {
                    sVar1 = *psVar7;
                    psVar7 = psVar7 + 1;
                  } while (sVar1 != 0);
                  FUN_00402160(psVar8,(int)psVar7 - (int)(psVar8 + 1) >> 1);
                }
                else {
                  psVar8 = local_38;
                  if (7 < *(uint *)(local_38 + 10)) {
                    psVar8 = *(short **)local_38;
                  }
                  if ((DAT_00fe5ae4 & 1) == 0) {
                    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
                    local_8 = 2;
                    FUN_00584c40(&DAT_00fe5ac4);
                    _atexit((_func_4879 *)&LAB_00bcf390);
                    local_8 = 0xffffffff;
                  }
                  local_44 = (char *)0x18;
                  FUN_005740f0(&local_44);
                  if (local_3c == DAT_00fe5ac8) {
                    pcVar2 = (code *)swi(3);
                    (*pcVar2)();
                    return;
                  }
                  uVar6 = FUN_00483f00(psVar8);
                  local_8 = 3;
                  FUN_00402800(uVar6);
                  if (7 < local_1c) {
                    FUN_0089120c(local_30);
                  }
                }
                goto LAB_0050989e;
              }
            }
            piVar4 = local_40;
            if (local_31 != '\0') goto LAB_0050989e;
          }
        }
        else {
          FUN_006edb60(&DAT_00c0ddc0,uVar3);
          piVar4 = local_40;
        }
        local_50 = iVar9 + 1;
        piVar10 = piVar10 + 8;
      } while (local_50 < *piVar4);
    }
    local_4c = local_4c + 1;
    piVar4 = piVar4 + 0x32a;
    local_40 = piVar4;
    if (1 < local_4c) {
LAB_0050989e:
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
  } while( true );
}

