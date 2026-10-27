
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Exceeded maximum restarts with more pending */

void FUN_004c2920(void)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  undefined1 *in_ECX;
  char *local_a4;
  int local_a0 [2];
  char local_98 [128];
  undefined1 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091e472;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = uVar2;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 0x14) = 0xf;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *in_ECX = 0;
  local_8 = 0;
  local_a4 = "/ExpeditionDeploy/Type[@idx=\'{0}\']/Character";
  local_18 = 0;
  pcVar4 = local_98;
  local_a0[0] = 0;
  cVar1 = '/';
  do {
    if (cVar1 == '{') {
      if (local_a4[1] != '{') {
        local_a0[0] = 1;
        goto LAB_004c2e09;
      }
      pcVar5 = local_98;
      if ((int)pcVar4 - (int)pcVar5 == 0x80) {
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        FUN_00401fc0(local_98,(int)pcVar5 - (int)(local_98 + 1));
        pcVar4 = local_98;
      }
      *pcVar4 = '{';
      pcVar4 = pcVar4 + 1;
      local_a4 = local_a4 + 2;
    }
    else {
      if (cVar1 == '}') {
        if (local_a0[0] != 0) {
          local_a0[1] = 0;
          local_a0[0] = -1;
          iVar3 = FUN_004ad850(local_a0,local_a0 + 1,local_a4,uVar2);
          if (local_a0[0] == 0) {
            *pcVar4 = '\0';
            pcVar4 = local_98;
            do {
              cVar1 = *pcVar4;
              pcVar4 = pcVar4 + 1;
            } while (cVar1 != '\0');
            FUN_00401fc0(local_98,(int)pcVar4 - (int)(local_98 + 1));
            pcVar4 = local_98;
            if (iVar3 == 0) {
              switch(local_a0[0]) {
              case 0x4c2d33:
                    /* WARNING: This code block may not be properly labeled as switch case */
                FUN_004ad910(&stack0x00000004);
              }
            }
            else {
              switch(local_a0[0]) {
              case 0x4c2a7e:
                    /* WARNING: This code block may not be properly labeled as switch case */
                FUN_004ad970(in_ECX);
                local_a4 = local_a4 + 1;
                local_a0[0] = 0;
                goto LAB_004c2e8d;
              }
            }
          }
          local_a4 = local_a4 + 1;
          local_a0[0] = 0;
          goto LAB_004c2e8d;
        }
        *pcVar4 = '}';
        pcVar4 = pcVar4 + 1;
        pcVar5 = local_98;
        if ((int)pcVar4 - (int)pcVar5 == 0x80) {
          do {
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          FUN_00401fc0(local_98,(int)pcVar5 - (int)(local_98 + 1));
          pcVar4 = local_98;
        }
      }
      else {
        if (local_a0[0] == 0) {
          *pcVar4 = cVar1;
          pcVar4 = pcVar4 + 1;
        }
LAB_004c2e09:
        pcVar5 = local_98;
        if ((int)pcVar4 - (int)pcVar5 == 0x80) {
          do {
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          FUN_00401fc0(local_98,(int)pcVar5 - (int)(local_98 + 1));
          pcVar4 = local_98;
          local_a4 = local_a4 + 1;
          goto LAB_004c2e8d;
        }
      }
      local_a4 = local_a4 + 1;
    }
LAB_004c2e8d:
    cVar1 = *local_a4;
    if (cVar1 == '\0') {
      pcVar5 = local_98;
      if (pcVar4 != pcVar5) {
        *pcVar4 = '\0';
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        FUN_00401fc0(local_98,(int)pcVar5 - (int)(local_98 + 1));
      }
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
  } while( true );
}

