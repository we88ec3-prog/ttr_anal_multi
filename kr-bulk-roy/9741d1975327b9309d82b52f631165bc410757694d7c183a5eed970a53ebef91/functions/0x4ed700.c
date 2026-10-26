
/* WARNING: Exceeded maximum restarts with more pending */

void FUN_004ed700(short *param_1)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  short *psVar4;
  undefined2 *in_EDX;
  short *psVar5;
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
  *(undefined4 *)(in_EDX + 10) = 7;
  *(undefined4 *)(in_EDX + 8) = 0;
  *in_EDX = 0;
  local_8 = 0;
  sVar1 = *param_1;
  local_18 = 0;
  psVar5 = &local_118;
  local_124 = 0;
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
        goto LAB_004edbc5;
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
              case 0x4edaff:
                    /* WARNING: This code block may not be properly labeled as switch case */
                FUN_00479e90();
              }
            }
            else {
              switch(local_124) {
              case 0x4ed874:
                    /* WARNING: This code block may not be properly labeled as switch case */
                FUN_00479d80(in_EDX);
                local_120 = local_120 + 1;
                local_124 = 0;
                goto LAB_004edc57;
              }
            }
          }
          local_120 = local_120 + 1;
          local_124 = 0;
          goto LAB_004edc57;
        }
        *psVar5 = 0x7d;
        psVar5 = psVar5 + 1;
        psVar4 = &local_118;
        if ((int)psVar5 - (int)psVar4 == 0x100) {
          do {
            sVar1 = *psVar4;
            psVar4 = psVar4 + 1;
          } while (sVar1 != 0);
          goto LAB_004edbeb;
        }
      }
      else {
        if (local_124 == 0) {
          *psVar5 = sVar1;
          psVar5 = psVar5 + 1;
        }
LAB_004edbc5:
        psVar4 = &local_118;
        if ((int)psVar5 - (int)psVar4 == 0x100) {
          do {
            sVar1 = *psVar4;
            psVar4 = psVar4 + 1;
          } while (sVar1 != 0);
LAB_004edbeb:
          FUN_00404300(&local_118,(int)psVar4 - (int)local_116 >> 1);
          psVar5 = &local_118;
        }
      }
      local_120 = local_120 + 1;
    }
LAB_004edc57:
    sVar1 = *local_120;
  } while( true );
}

