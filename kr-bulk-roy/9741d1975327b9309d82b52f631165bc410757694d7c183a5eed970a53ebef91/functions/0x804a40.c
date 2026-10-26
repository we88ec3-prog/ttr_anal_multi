
void FUN_00804a40(int param_1)

{
  undefined4 *puVar1;
  DWORD DVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  bool bVar6;
  undefined4 local_18;
  int *local_14;
  uint local_10;
  uint local_c;
  int local_8;
  
  DVar2 = timeGetTime();
  bVar6 = DAT_00fba858 == (int *)0x0;
  *(DWORD *)(param_1 + 0x48) = DVar2;
  if (bVar6) {
    if (DAT_00fba85c == 0) {
      FUN_0049b000();
    }
    else {
      FUN_0049af60();
    }
  }
  piVar4 = DAT_00fba858;
  local_14 = DAT_00fba858;
  local_8 = 0;
  DVar2 = timeGetTime();
  if (0x21 < *(int *)(param_1 + 0x88) - DVar2) {
    *(DWORD *)(param_1 + 0x88) = DVar2;
    local_8 = 1;
  }
  uVar5 = piVar4[1] - *piVar4 >> 2;
  local_10 = 0;
  local_c = uVar5;
  if (uVar5 != 0) {
    do {
      puVar1 = *(undefined4 **)(*piVar4 + local_10 * 4);
      if (puVar1[0x282b] != 0) {
        iVar3 = FUN_008061a0(puVar1);
        if (iVar3 == 0) {
          if (local_8 != 0) {
            puVar1[0x2821] = puVar1[0x2821] + 1;
            puVar1[0x2829] = puVar1[0x2829] + 5;
          }
        }
        else {
          puVar1[0x2825] = puVar1[0x2825] + 1;
          if ((uint)puVar1[0x2829] < 5) {
            puVar1[0x2829] = 0;
          }
          else {
            puVar1[0x2829] = puVar1[0x2829] - 5;
          }
        }
        local_18 = 0;
        if ((puVar1[0x280a] != 0) && ((int)puVar1[0x282e] < 1)) {
          iVar3 = (**(code **)(*DAT_00fba854 + 0xc))
                            (puVar1,puVar1 + 0x1408,puVar1[0x280a],&local_18);
          if (iVar3 == 0) {
            FUN_008063e0(puVar1);
            (**(code **)(*DAT_00fba854 + 0x24))(puVar1,0);
            puVar1[0x282a] = 1;
          }
          if (puVar1[0x282c] != 0) {
            (**(code **)(*DAT_00fba854 + 0x24))(puVar1,0);
            puVar1[0x282a] = 1;
          }
          uVar5 = local_c;
          if ((300 < (int)puVar1[0x2829]) && (puVar1[0x282a] == 0)) {
            FUN_008063e0(puVar1);
            if (*(int *)(param_1 + 0x8c) != 0) {
              FUN_006f0400(2,
                           "[FaultDisconnect %d] : TOTAL : [%08d] FT_LOADSENDSTREAM[%d, %d] FT_SENDPOST[%d, %d] FT_SENDPACKET[%d, %d] FT_TOOMANYSEND[%d, %d]"
                           ,*puVar1,puVar1[0x2829],puVar1[0x2821],puVar1[0x2825],puVar1[0x2822],
                           puVar1[0x2826],puVar1[0x2823],puVar1[0x2827],puVar1[0x2824],
                           puVar1[0x2828]);
            }
            if (puVar1[0x282d] == 2) {
              (**(code **)(*DAT_00fba854 + 0x1c))(puVar1);
              FUN_00806010();
            }
            else {
              (**(code **)(*DAT_00fba854 + 0x24))(puVar1,0);
            }
            puVar1[0x282a] = 1;
            uVar5 = local_c;
          }
        }
      }
      local_10 = local_10 + 1;
      piVar4 = local_14;
    } while (local_10 < uVar5);
  }
  DVar2 = timeGetTime();
  *(DWORD *)(param_1 + 0x4c) = DVar2;
  return;
}

