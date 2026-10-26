
void FUN_008fa5e0(int param_1)

{
  uint *puVar1;
  byte bVar2;
  void *pvVar3;
  void *pvVar4;
  int iVar5;
  int *in_EAX;
  undefined4 uVar6;
  byte bVar7;
  uint *in_ECX;
  uint uVar8;
  int iVar9;
  uint uVar10;
  undefined4 local_40;
  undefined4 local_3c;
  uint local_38;
  uint local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  void *local_14;
  uint local_10;
  byte *local_c;
  uint local_8;
  
  local_8 = in_ECX[8];
  uVar10 = in_ECX[7];
  local_c = (byte *)*in_EAX;
  local_10 = in_EAX[1];
  local_14 = (void *)in_ECX[0xd];
  if (local_14 < (void *)in_ECX[0xc]) {
    local_1c = (int)in_ECX[0xc] + (-1 - (int)local_14);
  }
  else {
    local_1c = in_ECX[0xb] - (int)local_14;
  }
  uVar8 = *in_ECX;
  local_18 = uVar10;
  do {
    if (9 < uVar8) {
      param_1 = -2;
LAB_008fad05:
      in_ECX[8] = local_8;
      in_ECX[7] = uVar10;
LAB_008fad0e:
      in_EAX[1] = local_10;
LAB_008fad14:
      iVar9 = (int)local_c - *in_EAX;
      *in_EAX = (int)local_c;
LAB_008fad1d:
      in_EAX[2] = in_EAX[2] + iVar9;
      in_ECX[0xd] = (uint)local_14;
      FUN_008f9df0(param_1);
      return;
    }
    switch(uVar8) {
    case 0:
      while (uVar10 < 3) {
        if (local_10 == 0) goto LAB_008fad35;
        local_10 = local_10 - 1;
        param_1 = 0;
        local_8 = local_8 | (uint)*local_c << ((byte)uVar10 & 0x1f);
        local_c = local_c + 1;
        uVar10 = uVar10 + 8;
        local_18 = uVar10;
      }
      in_ECX[6] = local_8 & 1;
      switch((local_8 & 7) >> 1) {
      case 0:
        uVar8 = uVar10 - 3 & 7;
        local_8 = (local_8 >> 3) >> (sbyte)uVar8;
        uVar10 = (uVar10 - 3) - uVar8;
        *in_ECX = 1;
        local_18 = uVar10;
        break;
      case 1:
        FUN_008f9dc0(&local_24);
        uVar8 = FUN_008f9ef0(local_30,local_2c,local_28,local_24);
        in_ECX[1] = uVar8;
        if (uVar8 == 0) {
          param_1 = -4;
          goto LAB_008fad05;
        }
        local_8 = local_8 >> 3;
        uVar10 = uVar10 - 3;
        *in_ECX = 6;
        local_18 = uVar10;
        break;
      case 2:
        local_8 = local_8 >> 3;
        uVar10 = uVar10 - 3;
        *in_ECX = 3;
        local_18 = uVar10;
        break;
      case 3:
        *in_ECX = 9;
        in_EAX[6] = (int)"invalid block type";
        in_ECX[8] = local_8 >> 3;
        in_ECX[7] = uVar10 - 3;
        in_EAX[1] = local_10;
        param_1 = -3;
        goto LAB_008fad14;
      }
      break;
    case 1:
      for (; uVar10 < 0x20; uVar10 = uVar10 + 8) {
        if (local_10 == 0) {
          in_ECX[8] = local_8;
          in_ECX[7] = uVar10;
          in_EAX[1] = 0;
          iVar9 = (int)local_c - *in_EAX;
          *in_EAX = (int)local_c;
          goto LAB_008fad1d;
        }
        bVar7 = *local_c;
        local_10 = local_10 - 1;
        local_c = local_c + 1;
        param_1 = 0;
        local_8 = local_8 | (uint)bVar7 << ((byte)uVar10 & 0x1f);
      }
      uVar8 = local_8 & 0xffff;
      if (~local_8 >> 0x10 != uVar8) {
        *in_ECX = 9;
        in_EAX[6] = (int)"invalid stored block lengths";
        param_1 = -3;
        goto LAB_008fad05;
      }
      in_ECX[1] = uVar8;
      local_18 = 0;
      local_8 = 0;
      if (uVar8 == 0) {
        uVar10 = 0;
        *in_ECX = -(uint)(in_ECX[6] != 0) & 7;
      }
      else {
        uVar10 = 0;
        *in_ECX = 2;
      }
      break;
    case 2:
      if (local_10 == 0) {
LAB_008fad35:
        in_ECX[8] = local_8;
LAB_008fad3b:
        in_ECX[7] = uVar10;
        iVar9 = (int)local_c - *in_EAX;
        *in_EAX = (int)local_c;
        in_EAX[1] = 0;
        goto LAB_008fad1d;
      }
      if (local_1c == 0) {
        local_1c = 0;
        if (local_14 == (void *)in_ECX[0xb]) {
          pvVar3 = (void *)in_ECX[0xc];
          pvVar4 = (void *)in_ECX[10];
          if (pvVar4 != pvVar3) {
            if (pvVar4 < pvVar3) {
              local_1c = (int)pvVar3 + (-1 - (int)pvVar4);
            }
            else {
              local_1c = (int)in_ECX[0xb] - (int)pvVar4;
            }
            local_14 = pvVar4;
            if (local_1c != 0) goto LAB_008fa833;
          }
        }
        in_ECX[0xd] = (uint)local_14;
        param_1 = FUN_008f9df0(param_1);
        pvVar3 = (void *)in_ECX[0xc];
        local_14 = (void *)in_ECX[0xd];
        if (local_14 < pvVar3) {
          local_1c = (int)pvVar3 + (-1 - (int)local_14);
        }
        else {
          local_1c = in_ECX[0xb] - (int)local_14;
        }
        if (local_14 == (void *)in_ECX[0xb]) {
          pvVar4 = (void *)in_ECX[10];
          if (pvVar4 != pvVar3) {
            local_14 = pvVar4;
            if (pvVar4 < pvVar3) {
              local_1c = (int)pvVar3 + (-1 - (int)pvVar4);
            }
            else {
              local_1c = in_ECX[0xb] - (int)pvVar4;
            }
          }
        }
        if (local_1c == 0) {
          in_ECX[8] = local_8;
          in_ECX[7] = uVar10;
          iVar9 = (int)local_c - *in_EAX;
          *in_EAX = (int)local_c;
          in_EAX[1] = local_10;
          goto LAB_008fad1d;
        }
      }
LAB_008fa833:
      param_1 = 0;
      local_20 = in_ECX[1];
      if (local_10 < in_ECX[1]) {
        local_20 = local_10;
      }
      if (local_1c < local_20) {
        local_20 = local_1c;
      }
      FID_conflict__memcpy(local_14,local_c,local_20);
      local_c = local_c + local_20;
      local_10 = local_10 - local_20;
      local_14 = (void *)((int)local_14 + local_20);
      local_1c = local_1c - local_20;
      puVar1 = in_ECX + 1;
      *puVar1 = *puVar1 - local_20;
      if (*puVar1 == 0) {
        *in_ECX = -(uint)(in_ECX[6] != 0) & 7;
      }
      break;
    case 3:
      for (; uVar10 < 0xe; uVar10 = uVar10 + 8) {
        if (local_10 == 0) goto LAB_008fadce;
        local_10 = local_10 - 1;
        param_1 = 0;
        local_8 = local_8 | (uint)*local_c << ((byte)uVar10 & 0x1f);
        local_c = local_c + 1;
      }
      in_ECX[1] = local_8 & 0x3fff;
      if ((0x1d < (local_8 & 0x1f)) || (uVar8 = (local_8 & 0x3fff) >> 5 & 0x1f, 0x1d < uVar8)) {
        *in_ECX = 9;
        in_EAX[6] = (int)"too many length or distance symbols";
        goto switchD_008fa638_caseD_9;
      }
      uVar8 = (*(code *)in_EAX[8])(in_EAX[10],uVar8 + 0x102 + (local_8 & 0x1f),4);
      in_ECX[3] = uVar8;
      if (uVar8 != 0) {
        local_8 = local_8 >> 0xe;
        uVar10 = uVar10 - 0xe;
        in_ECX[2] = 0;
        *in_ECX = 4;
        local_18 = uVar10;
        goto switchD_008fa638_caseD_4;
      }
      in_ECX[8] = local_8;
      in_ECX[7] = uVar10;
      in_EAX[1] = local_10;
      param_1 = -4;
      goto LAB_008fad14;
    case 4:
switchD_008fa638_caseD_4:
      if (in_ECX[2] < (in_ECX[1] >> 10) + 4) {
        do {
          for (; uVar10 < 3; uVar10 = uVar10 + 8) {
            if (local_10 == 0) {
LAB_008fadce:
              in_ECX[8] = local_8;
              in_ECX[7] = uVar10;
              iVar9 = *in_EAX;
              *in_EAX = (int)local_c;
              in_EAX[2] = (int)(local_c + (in_EAX[2] - iVar9));
              in_EAX[1] = 0;
              in_ECX[0xd] = (uint)local_14;
              FUN_008f9df0(param_1);
              return;
            }
            local_10 = local_10 - 1;
            param_1 = 0;
            local_8 = local_8 | (uint)*local_c << ((byte)uVar10 & 0x1f);
            local_c = local_c + 1;
          }
          *(uint *)(in_ECX[3] + *(int *)(&DAT_00bed070 + in_ECX[2] * 4) * 4) = local_8 & 7;
          in_ECX[2] = in_ECX[2] + 1;
          local_8 = local_8 >> 3;
          local_18 = uVar10 - 3;
          uVar10 = local_18;
        } while (in_ECX[2] < (in_ECX[1] >> 10) + 4);
      }
      uVar10 = in_ECX[2];
      while (uVar10 < 0x13) {
        *(undefined4 *)(in_ECX[3] + *(int *)(&DAT_00bed070 + in_ECX[2] * 4) * 4) = 0;
        in_ECX[2] = in_ECX[2] + 1;
        uVar10 = in_ECX[2];
      }
      in_ECX[4] = 7;
      iVar9 = FUN_008f9bc0(in_ECX[3],in_ECX + 4,in_ECX + 5,in_ECX[9]);
      if (iVar9 != 0) {
        if (iVar9 == -3) {
          (*(code *)in_EAX[9])(in_EAX[10],in_ECX[3]);
          *in_ECX = 9;
        }
        in_ECX[7] = local_18;
        in_ECX[8] = local_8;
        iVar5 = *in_EAX;
        *in_EAX = (int)local_c;
        in_EAX[2] = (int)(local_c + (in_EAX[2] - iVar5));
        in_EAX[1] = local_10;
        in_ECX[0xd] = (uint)local_14;
        FUN_008f9df0(iVar9);
        return;
      }
      in_ECX[2] = 0;
      *in_ECX = 5;
      uVar10 = local_18;
switchD_008fa638_caseD_5:
      if (in_ECX[2] < (in_ECX[1] >> 5 & 0x1f) + 0x102 + (in_ECX[1] & 0x1f)) {
        do {
          uVar8 = in_ECX[4];
          if (uVar10 < uVar8) {
            do {
              if (local_10 == 0) goto LAB_008fadce;
              local_10 = local_10 - 1;
              bVar7 = (byte)uVar10;
              uVar8 = in_ECX[4];
              uVar10 = uVar10 + 8;
              param_1 = 0;
              local_8 = local_8 | (uint)*local_c << (bVar7 & 0x1f);
              local_c = local_c + 1;
            } while (uVar10 < uVar8);
          }
          iVar9 = in_ECX[5] + (*(uint *)(&DAT_00bed028 + uVar8 * 4) & local_8) * 8;
          bVar7 = *(byte *)(iVar9 + 1);
          local_20 = (uint)bVar7;
          local_38 = *(uint *)(iVar9 + 4);
          if (local_38 < 0x10) {
            local_8 = local_8 >> (bVar7 & 0x1f);
            uVar10 = uVar10 - local_20;
            *(uint *)(in_ECX[3] + in_ECX[2] * 4) = local_38;
            in_ECX[2] = in_ECX[2] + 1;
          }
          else {
            if (local_38 == 0x12) {
              local_18 = 7;
            }
            else {
              local_18 = local_38 - 0xe;
            }
            local_1c = (uint)(local_38 == 0x12) * 8 + 3;
            local_34 = local_20 + local_18;
            for (; uVar10 < local_34; uVar10 = uVar10 + 8) {
              if (local_10 == 0) {
                in_ECX[8] = local_8;
                goto LAB_008fad3b;
              }
              local_10 = local_10 - 1;
              bVar2 = *local_c;
              local_c = local_c + 1;
              local_8 = local_8 | (uint)bVar2 << ((byte)uVar10 & 0x1f);
              param_1 = 0;
            }
            local_8 = local_8 >> (bVar7 & 0x1f);
            local_1c = local_1c + (*(uint *)(&DAT_00bed028 + local_18 * 4) & local_8);
            local_8 = local_8 >> ((byte)local_18 & 0x1f);
            uVar10 = uVar10 - (local_18 + local_20);
            uVar8 = in_ECX[2];
            if ((in_ECX[1] >> 5 & 0x1f) + 0x102 + (in_ECX[1] & 0x1f) < local_1c + uVar8) {
LAB_008faeb2:
              local_18 = uVar10;
              (*(code *)in_EAX[9])(in_EAX[10],in_ECX[3]);
              *in_ECX = 9;
              in_EAX[6] = (int)"invalid bit length repeat";
              in_ECX[8] = local_8;
              in_ECX[7] = uVar10;
              in_EAX[1] = local_10;
              in_EAX[2] = (int)(local_c + (in_EAX[2] - *in_EAX));
              *in_EAX = (int)local_c;
              in_ECX[0xd] = (uint)local_14;
              FUN_008f9df0(0xfffffffd);
              return;
            }
            if (local_38 == 0x10) {
              if (uVar8 == 0) goto LAB_008faeb2;
              uVar6 = *(undefined4 *)((in_ECX[3] - 4) + uVar8 * 4);
            }
            else {
              uVar6 = 0;
            }
            do {
              *(undefined4 *)(in_ECX[3] + uVar8 * 4) = uVar6;
              uVar8 = uVar8 + 1;
              local_1c = local_1c - 1;
            } while (local_1c != 0);
            in_ECX[2] = uVar8;
            local_1c = 0;
          }
          local_18 = uVar10;
        } while (in_ECX[2] < (in_ECX[1] >> 5 & 0x1f) + 0x102 + (in_ECX[1] & 0x1f));
      }
      in_ECX[5] = 0;
      local_1c = 9;
      local_20 = 6;
      iVar9 = FUN_008f9c50((in_ECX[1] & 0x1f) + 0x101,(in_ECX[1] >> 5 & 0x1f) + 1,in_ECX[3],
                           &local_1c,&local_20,&local_40,&local_3c,in_ECX[9]);
      if (iVar9 != 0) {
        if (iVar9 == -3) {
          (*(code *)in_EAX[9])(in_EAX[10],in_ECX[3]);
          *in_ECX = 9;
        }
        in_ECX[8] = local_8;
        in_ECX[7] = local_18;
        param_1 = iVar9;
        goto LAB_008fad0e;
      }
      uVar10 = FUN_008f9ef0(local_1c,local_20,local_40,local_3c);
      if (uVar10 == 0) {
        in_ECX[8] = local_8;
        in_ECX[7] = local_18;
        param_1 = -4;
        goto LAB_008fad0e;
      }
      in_ECX[1] = uVar10;
      (*(code *)in_EAX[9])(in_EAX[10],in_ECX[3]);
      *in_ECX = 6;
      uVar10 = local_18;
switchD_008fa638_caseD_6:
      in_ECX[8] = local_8;
      in_ECX[7] = uVar10;
      in_EAX[1] = local_10;
      in_EAX[2] = (int)(local_c + (in_EAX[2] - *in_EAX));
      *in_EAX = (int)local_c;
      in_ECX[0xd] = (uint)local_14;
      iVar9 = FUN_008f9f30(param_1);
      if (iVar9 != 1) {
LAB_008faf82:
        FUN_008f9df0(iVar9);
        return;
      }
      param_1 = 0;
      FUN_008fa4c0();
      local_10 = in_EAX[1];
      local_8 = in_ECX[8];
      local_c = (byte *)*in_EAX;
      local_14 = (void *)in_ECX[0xd];
      uVar10 = in_ECX[7];
      if (local_14 < (void *)in_ECX[0xc]) {
        local_1c = (int)in_ECX[0xc] + (-1 - (int)local_14);
      }
      else {
        local_1c = in_ECX[0xb] - (int)local_14;
      }
      local_18 = uVar10;
      if (in_ECX[6] != 0) {
        *in_ECX = 7;
switchD_008fa638_caseD_7:
        in_ECX[0xd] = (uint)local_14;
        iVar9 = FUN_008f9df0(param_1);
        local_14 = (void *)in_ECX[0xd];
        if ((void *)in_ECX[0xc] != local_14) {
          in_ECX[8] = local_8;
          in_ECX[7] = uVar10;
          in_EAX[1] = local_10;
          iVar5 = *in_EAX;
          *in_EAX = (int)local_c;
          in_EAX[2] = (int)(local_c + (in_EAX[2] - iVar5));
          in_ECX[0xd] = (uint)local_14;
          goto LAB_008faf82;
        }
        *in_ECX = 8;
switchD_008fa638_caseD_8:
        in_ECX[8] = local_8;
        in_ECX[7] = uVar10;
        in_EAX[1] = local_10;
        param_1 = 1;
        goto LAB_008fad14;
      }
      *in_ECX = 0;
      break;
    case 5:
      goto switchD_008fa638_caseD_5;
    case 6:
      goto switchD_008fa638_caseD_6;
    case 7:
      goto switchD_008fa638_caseD_7;
    case 8:
      goto switchD_008fa638_caseD_8;
    case 9:
switchD_008fa638_caseD_9:
      in_ECX[8] = local_8;
      in_ECX[7] = uVar10;
      iVar9 = *in_EAX;
      *in_EAX = (int)local_c;
      in_EAX[2] = (int)(local_c + (in_EAX[2] - iVar9));
      in_EAX[1] = local_10;
      in_ECX[0xd] = (uint)local_14;
      FUN_008f9df0(0xfffffffd);
      return;
    }
    uVar8 = *in_ECX;
  } while( true );
}

