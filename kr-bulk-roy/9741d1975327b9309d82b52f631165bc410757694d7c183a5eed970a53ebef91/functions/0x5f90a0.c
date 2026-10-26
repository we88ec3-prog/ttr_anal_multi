
/* WARNING: Exceeded maximum restarts with more pending */

void FUN_005f90a0(short *param_1)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  short *psVar4;
  undefined2 *in_ECX;
  short *psVar5;
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  short *local_128;
  int local_124;
  short *local_120;
  undefined4 local_11c;
  short local_118;
  undefined1 local_116 [254];
  undefined2 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091c072;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = uVar2;
  ExceptionList = &local_10;
  local_138 = 0;
  local_134 = 0;
  local_13c = 0;
  local_12c = 0;
  local_130 = 0;
  local_140 = 0x2d;
  *(undefined4 *)(in_ECX + 10) = 7;
  *(undefined4 *)(in_ECX + 8) = 0;
  *in_ECX = 0;
  local_8 = 0;
  sVar1 = *param_1;
  local_18 = 0;
  psVar5 = &local_118;
  local_124 = 0;
  local_128 = (short *)0x0;
  local_120 = param_1;
  do {
    if (sVar1 == 0) {
      psVar4 = &local_118;
      if (psVar5 != psVar4) {
        *psVar5 = 0;
        do {
          sVar1 = *psVar4;
          psVar4 = psVar4 + 1;
        } while (sVar1 != 0);
        FUN_00404300(&local_118,(int)psVar4 - (int)local_116 >> 1);
      }
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
    if (sVar1 == 0x7b) {
      if (local_120[1] != 0x7b) {
        local_124 = 1;
        local_128 = local_120;
        goto LAB_005f9574;
      }
      psVar4 = &local_118;
      if ((int)psVar5 - (int)psVar4 == 0x100) {
        do {
          sVar1 = *psVar4;
          psVar4 = psVar4 + 1;
        } while (sVar1 != 0);
        FUN_00404300(&local_118,(int)psVar4 - (int)local_116 >> 1);
        psVar5 = &local_118;
      }
      *psVar5 = 0x7b;
      psVar5 = psVar5 + 1;
      local_120 = local_120 + 2;
    }
    else {
      if (sVar1 == 0x7d) {
        if (local_124 != 0) {
          local_124 = -1;
          local_11c = 0;
          iVar3 = FUN_00403e00(&local_124,&local_11c,local_120,uVar2);
          if (local_124 == 0) {
            psVar4 = &local_118;
            *psVar5 = 0;
            do {
              sVar1 = *psVar4;
              psVar4 = psVar4 + 1;
            } while (sVar1 != 0);
            FUN_00404300(&local_118,(int)psVar4 - (int)local_116 >> 1);
            psVar5 = &local_118;
            if (iVar3 == 0) {
              switch(local_124) {
              case 0x5f94a1:
                    /* WARNING: This code block may not be properly labeled as switch case */
                FUN_0042ecb0(&local_140);
              }
            }
            else {
              switch(local_124) {
              case 0x5f9216:
                    /* WARNING: This code block may not be properly labeled as switch case */
                FUN_0042efa0(in_ECX);
                local_120 = local_120 + 1;
                local_124 = 0;
                goto LAB_005f9608;
              }
            }
          }
          local_120 = local_120 + 1;
          local_124 = 0;
          goto LAB_005f9608;
        }
        *psVar5 = 0x7d;
        psVar5 = psVar5 + 1;
        psVar4 = &local_118;
        if ((int)psVar5 - (int)psVar4 == 0x100) {
          do {
            sVar1 = *psVar4;
            psVar4 = psVar4 + 1;
          } while (sVar1 != 0);
          goto LAB_005f959b;
        }
      }
      else {
        if (local_124 == 0) {
          *psVar5 = sVar1;
          psVar5 = psVar5 + 1;
        }
LAB_005f9574:
        psVar4 = &local_118;
        if ((int)psVar5 - (int)psVar4 == 0x100) {
          do {
            sVar1 = *psVar4;
            psVar4 = psVar4 + 1;
          } while (sVar1 != 0);
LAB_005f959b:
          FUN_00404300(&local_118,(int)psVar4 - (int)local_116 >> 1);
          psVar5 = &local_118;
        }
      }
      local_120 = local_120 + 1;
    }
LAB_005f9608:
    sVar1 = *local_120;
  } while( true );
}

