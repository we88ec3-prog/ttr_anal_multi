
/* WARNING: Exceeded maximum restarts with more pending */

void FUN_00438540(short *param_1)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  short *psVar4;
  undefined2 *in_ECX;
  short *psVar5;
  int local_128;
  short *local_124;
  undefined4 local_120;
  short local_11c;
  undefined1 local_11a [254];
  undefined2 local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00921322;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = uVar2;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 10) = 7;
  *(undefined4 *)(in_ECX + 8) = 0;
  *in_ECX = 0;
  local_8 = 0;
  sVar1 = *param_1;
  local_1c = 0;
  psVar5 = &local_11c;
  local_128 = 0;
  local_124 = param_1;
  do {
    if (sVar1 == 0) {
      psVar4 = &local_11c;
      if (psVar5 != psVar4) {
        *psVar5 = 0;
        do {
          sVar1 = *psVar4;
          psVar4 = psVar4 + 1;
        } while (sVar1 != 0);
        FUN_00404300(&local_11c,(int)psVar4 - (int)local_11a >> 1);
      }
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
    if (sVar1 == 0x7b) {
      if (local_124[1] != 0x7b) {
        local_128 = 1;
        goto LAB_00438a04;
      }
      psVar4 = &local_11c;
      if ((int)psVar5 - (int)psVar4 == 0x100) {
        do {
          sVar1 = *psVar4;
          psVar4 = psVar4 + 1;
        } while (sVar1 != 0);
        FUN_00404300(&local_11c,(int)psVar4 - (int)local_11a >> 1);
        psVar5 = &local_11c;
      }
      *psVar5 = 0x7b;
      psVar5 = psVar5 + 1;
      local_124 = local_124 + 2;
    }
    else {
      if (sVar1 == 0x7d) {
        if (local_128 != 0) {
          local_128 = -1;
          local_120 = 0;
          iVar3 = FUN_00403e00(&local_128,&local_120,local_124,uVar2);
          if (local_128 == 0) {
            psVar4 = &local_11c;
            *psVar5 = 0;
            do {
              sVar1 = *psVar4;
              psVar4 = psVar4 + 1;
            } while (sVar1 != 0);
            FUN_00404300(&local_11c,(int)psVar4 - (int)local_11a >> 1);
            psVar5 = &local_11c;
            if (iVar3 == 0) {
              switch(local_128) {
              case 0x438938:
                    /* WARNING: This code block may not be properly labeled as switch case */
                FUN_00438b50(&stack0x00000008);
              }
            }
            else {
              switch(local_128) {
              case 0x4386b0:
                    /* WARNING: This code block may not be properly labeled as switch case */
                FUN_00438c60(in_ECX);
                local_124 = local_124 + 1;
                local_128 = 0;
                goto LAB_00438a98;
              }
            }
          }
          local_124 = local_124 + 1;
          local_128 = 0;
          goto LAB_00438a98;
        }
        *psVar5 = 0x7d;
        psVar5 = psVar5 + 1;
        psVar4 = &local_11c;
        if ((int)psVar5 - (int)psVar4 == 0x100) {
          do {
            sVar1 = *psVar4;
            psVar4 = psVar4 + 1;
          } while (sVar1 != 0);
          goto LAB_00438a2b;
        }
      }
      else {
        if (local_128 == 0) {
          *psVar5 = sVar1;
          psVar5 = psVar5 + 1;
        }
LAB_00438a04:
        psVar4 = &local_11c;
        if ((int)psVar5 - (int)psVar4 == 0x100) {
          do {
            sVar1 = *psVar4;
            psVar4 = psVar4 + 1;
          } while (sVar1 != 0);
LAB_00438a2b:
          FUN_00404300(&local_11c,(int)psVar4 - (int)local_11a >> 1);
          psVar5 = &local_11c;
        }
      }
      local_124 = local_124 + 1;
    }
LAB_00438a98:
    sVar1 = *local_124;
  } while( true );
}

