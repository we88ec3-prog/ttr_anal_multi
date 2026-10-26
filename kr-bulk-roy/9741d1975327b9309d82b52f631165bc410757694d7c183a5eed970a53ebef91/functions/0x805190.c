
void FUN_00805190(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  undefined4 local_10;
  int *local_c;
  uint local_8;
  
  if (param_1 != (int *)0x0) {
    iVar1 = *(int *)(param_1[5] + 0xa4);
    while ((iVar1 != 0 &&
           (WaitForSingleObject((HANDLE)param_1[2],0xffffffff), *(int *)(param_1[5] + 0xa4) != 0)))
    {
      if (DAT_00fba858 == (int *)0x0) {
        if (DAT_00fba85c == 0) {
          FUN_0049b000();
        }
        else {
          FUN_0049af60();
        }
      }
      iVar1 = DAT_00fba858[1];
      iVar2 = *DAT_00fba858;
      local_c = DAT_00fba858;
      for (uVar5 = param_1[1]; local_8 = uVar5, uVar5 < (uint)(iVar1 - iVar2 >> 2);
          uVar5 = uVar5 + *param_1) {
        puVar3 = *(undefined4 **)(*local_c + uVar5 * 4);
        if (puVar3[0x282b] != 0) {
          iVar4 = FUN_008061a0(puVar3);
          if (iVar4 == 0) {
            if ((char)param_1[4] != '\0') {
              puVar3[0x2821] = puVar3[0x2821] + 1;
              puVar3[0x2829] = puVar3[0x2829] + 5;
            }
          }
          else {
            puVar3[0x2825] = puVar3[0x2825] + 1;
            if ((uint)puVar3[0x2829] < 5) {
              puVar3[0x2829] = 0;
            }
            else {
              puVar3[0x2829] = puVar3[0x2829] - 5;
            }
          }
          local_10 = 0;
          if ((puVar3[0x280a] != 0) && ((int)puVar3[0x282e] < 1)) {
            iVar4 = (**(code **)(*DAT_00fba854 + 0xc))
                              (puVar3,puVar3 + 0x1408,puVar3[0x280a],&local_10);
            if (iVar4 == 0) {
              FUN_008063e0(puVar3);
              (**(code **)(*DAT_00fba854 + 0x24))(puVar3,0);
              puVar3[0x282a] = 1;
            }
            if (puVar3[0x282c] != 0) {
              (**(code **)(*DAT_00fba854 + 0x24))(puVar3,0);
              puVar3[0x282a] = 1;
            }
            uVar5 = local_8;
            if ((300 < (int)puVar3[0x2829]) && (puVar3[0x282a] == 0)) {
              FUN_008063e0(puVar3);
              if (*(int *)(param_1[5] + 0x8c) != 0) {
                FUN_006f0400(2,
                             "[FaultDisconnect %d] : TOTAL : [%08d] FT_LOADSENDSTREAM[%d, %d] FT_SENDPOST[%d, %d] FT_SENDPACKET[%d, %d] FT_TOOMANYSEND[%d, %d]"
                             ,*puVar3,puVar3[0x2829],puVar3[0x2821],puVar3[0x2825],puVar3[0x2822],
                             puVar3[0x2826],puVar3[0x2823],puVar3[0x2827],puVar3[0x2824],
                             puVar3[0x2828]);
              }
              if (puVar3[0x282d] == 2) {
                (**(code **)(*DAT_00fba854 + 0x1c))(puVar3);
                FUN_00806010();
              }
              else {
                (**(code **)(*DAT_00fba854 + 0x24))(puVar3,0);
              }
              puVar3[0x282a] = 1;
              uVar5 = local_8;
            }
          }
        }
      }
      SetEvent((HANDLE)param_1[3]);
      iVar1 = *(int *)(param_1[5] + 0xa4);
    }
    SetEvent((HANDLE)param_1[3]);
    __endthread();
  }
  return;
}

