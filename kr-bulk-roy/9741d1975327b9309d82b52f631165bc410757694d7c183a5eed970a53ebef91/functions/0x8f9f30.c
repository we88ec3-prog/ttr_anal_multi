
void FUN_008f9f30(undefined4 param_1)

{
  byte bVar1;
  undefined1 uVar2;
  uint *puVar3;
  undefined1 *puVar4;
  int iVar5;
  int *in_EAX;
  int in_ECX;
  uint uVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  uint uVar9;
  undefined4 uVar10;
  byte *local_1c;
  undefined1 *local_18;
  int local_14;
  byte *local_c;
  uint local_8;
  
  uVar9 = *(uint *)(in_ECX + 0x1c);
  local_c = (byte *)*in_EAX;
  local_14 = in_EAX[1];
  puVar3 = *(uint **)(in_ECX + 4);
  local_8 = *(uint *)(in_ECX + 0x20);
  puVar8 = *(undefined1 **)(in_ECX + 0x34);
  if (puVar8 < *(undefined1 **)(in_ECX + 0x30)) {
    local_18 = *(undefined1 **)(in_ECX + 0x30) + (-1 - (int)puVar8);
  }
  else {
    local_18 = (undefined1 *)(*(int *)(in_ECX + 0x2c) - (int)puVar8);
  }
  uVar6 = *puVar3;
  while (uVar6 < 10) {
    switch(uVar6) {
    case 0:
      puVar3[3] = (uint)(byte)puVar3[4];
      puVar3[2] = puVar3[5];
      *puVar3 = 1;
    case 1:
      for (; uVar9 < puVar3[3]; uVar9 = uVar9 + 8) {
        if (local_14 == 0) goto LAB_008fa3ab;
        local_14 = local_14 + -1;
        bVar1 = *local_c;
        local_c = local_c + 1;
        local_8 = local_8 | (uint)bVar1 << ((byte)uVar9 & 0x1f);
        param_1 = 0;
      }
      local_1c = (byte *)(puVar3[2] + (*(uint *)(&DAT_00bed028 + puVar3[3] * 4) & local_8) * 8);
      local_8 = local_8 >> (local_1c[1] & 0x1f);
      uVar9 = uVar9 - local_1c[1];
      bVar1 = *local_1c;
      uVar6 = (uint)bVar1;
      if (uVar6 == 0) {
        puVar3[2] = *(uint *)(local_1c + 4);
        *puVar3 = 6;
      }
      else if ((bVar1 & 0x10) == 0) {
        if ((bVar1 & 0x40) == 0) goto LAB_008fa048;
        if ((bVar1 & 0x20) == 0) {
          *puVar3 = 9;
          in_EAX[6] = (int)"invalid literal/length code";
          goto LAB_008fa3ea;
        }
        *puVar3 = 7;
      }
      else {
        puVar3[2] = uVar6 & 0xf;
        puVar3[1] = *(uint *)(local_1c + 4);
        *puVar3 = 2;
      }
      break;
    case 2:
      uVar6 = puVar3[2];
      for (; uVar9 < uVar6; uVar9 = uVar9 + 8) {
        if (local_14 == 0) goto LAB_008fa3ab;
        local_14 = local_14 + -1;
        bVar1 = *local_c;
        local_c = local_c + 1;
        local_8 = local_8 | (uint)bVar1 << ((byte)uVar9 & 0x1f);
        param_1 = 0;
      }
      puVar3[1] = puVar3[1] + (*(uint *)(&DAT_00bed028 + uVar6 * 4) & local_8);
      local_8 = local_8 >> ((byte)uVar6 & 0x1f);
      uVar9 = uVar9 - uVar6;
      puVar3[3] = (uint)*(byte *)((int)puVar3 + 0x11);
      puVar3[2] = puVar3[6];
      *puVar3 = 3;
    case 3:
      for (; uVar9 < puVar3[3]; uVar9 = uVar9 + 8) {
        if (local_14 == 0) goto LAB_008fa3ab;
        local_14 = local_14 + -1;
        bVar1 = *local_c;
        local_c = local_c + 1;
        local_8 = local_8 | (uint)bVar1 << ((byte)uVar9 & 0x1f);
        param_1 = 0;
      }
      local_1c = (byte *)(puVar3[2] + (*(uint *)(&DAT_00bed028 + puVar3[3] * 4) & local_8) * 8);
      local_8 = local_8 >> (local_1c[1] & 0x1f);
      uVar9 = uVar9 - local_1c[1];
      bVar1 = *local_1c;
      uVar6 = (uint)bVar1;
      if ((bVar1 & 0x10) == 0) {
        if ((bVar1 & 0x40) != 0) {
          *puVar3 = 9;
          in_EAX[6] = (int)"invalid distance code";
LAB_008fa3ea:
          *(uint *)(in_ECX + 0x20) = local_8;
          *(uint *)(in_ECX + 0x1c) = uVar9;
          in_EAX[1] = local_14;
          uVar10 = 0xfffffffd;
          goto LAB_008fa38d;
        }
LAB_008fa048:
        puVar3[3] = uVar6;
        puVar3[2] = (uint)(local_1c + *(int *)(local_1c + 4) * 8);
      }
      else {
        puVar3[2] = uVar6 & 0xf;
        puVar3[3] = *(uint *)(local_1c + 4);
        *puVar3 = 4;
      }
      break;
    case 4:
      uVar6 = puVar3[2];
      for (; uVar9 < uVar6; uVar9 = uVar9 + 8) {
        if (local_14 == 0) goto LAB_008fa3ab;
        local_14 = local_14 + -1;
        bVar1 = *local_c;
        local_c = local_c + 1;
        local_8 = local_8 | (uint)bVar1 << ((byte)uVar9 & 0x1f);
        param_1 = 0;
      }
      puVar3[3] = puVar3[3] + (*(uint *)(&DAT_00bed028 + uVar6 * 4) & local_8);
      local_8 = local_8 >> ((byte)uVar6 & 0x1f);
      uVar9 = uVar9 - uVar6;
      *puVar3 = 5;
    case 5:
      local_1c = puVar8 + -puVar3[3];
      if (local_1c < *(undefined1 **)(in_ECX + 0x28)) {
        do {
          local_1c = local_1c + (*(int *)(in_ECX + 0x2c) - (int)*(undefined1 **)(in_ECX + 0x28));
        } while (local_1c < *(undefined1 **)(in_ECX + 0x28));
      }
      uVar6 = puVar3[1];
      while (uVar6 != 0) {
        puVar7 = puVar8;
        if (local_18 == (undefined1 *)0x0) {
          if (puVar8 == *(undefined1 **)(in_ECX + 0x2c)) {
            local_18 = *(undefined1 **)(in_ECX + 0x30);
            puVar7 = *(undefined1 **)(in_ECX + 0x28);
            if (local_18 != puVar7) {
              if (puVar7 < local_18) {
                local_18 = local_18 + (-1 - (int)puVar7);
              }
              else {
                local_18 = (undefined1 *)(*(int *)(in_ECX + 0x2c) - (int)puVar7);
              }
              puVar8 = puVar7;
              if (local_18 != (undefined1 *)0x0) goto LAB_008fa2a3;
            }
          }
          *(undefined1 **)(in_ECX + 0x34) = puVar8;
          param_1 = FUN_008f9df0(param_1);
          puVar7 = *(undefined1 **)(in_ECX + 0x34);
          puVar8 = *(undefined1 **)(in_ECX + 0x30);
          if (puVar7 < puVar8) {
            local_18 = puVar8 + (-1 - (int)puVar7);
          }
          else {
            local_18 = (undefined1 *)(*(int *)(in_ECX + 0x2c) - (int)puVar7);
          }
          if ((puVar7 == *(undefined1 **)(in_ECX + 0x2c)) &&
             (puVar4 = *(undefined1 **)(in_ECX + 0x28), puVar8 != puVar4)) {
            puVar7 = puVar4;
            if (puVar4 < puVar8) {
              local_18 = puVar8 + (-1 - (int)puVar4);
            }
            else {
              local_18 = (undefined1 *)(*(int *)(in_ECX + 0x2c) - (int)puVar4);
            }
          }
          if (local_18 == (undefined1 *)0x0) goto LAB_008fa3fd;
        }
LAB_008fa2a3:
        uVar2 = *local_1c;
        local_1c = local_1c + 1;
        local_18 = local_18 + -1;
        *puVar7 = uVar2;
        puVar8 = puVar7 + 1;
        param_1 = 0;
        if (local_1c == *(undefined1 **)(in_ECX + 0x2c)) {
          local_1c = *(byte **)(in_ECX + 0x28);
        }
        puVar3[1] = puVar3[1] - 1;
        uVar6 = puVar3[1];
      }
      goto LAB_008fa36b;
    case 6:
      puVar7 = puVar8;
      if (local_18 == (undefined1 *)0x0) {
        if (puVar8 == *(undefined1 **)(in_ECX + 0x2c)) {
          local_18 = *(undefined1 **)(in_ECX + 0x30);
          puVar7 = *(undefined1 **)(in_ECX + 0x28);
          if (local_18 != puVar7) {
            if (puVar7 < local_18) {
              local_18 = local_18 + (-1 - (int)puVar7);
            }
            else {
              local_18 = (undefined1 *)(*(int *)(in_ECX + 0x2c) - (int)puVar7);
            }
            puVar8 = puVar7;
            if (local_18 != (undefined1 *)0x0) goto LAB_008fa35b;
          }
        }
        *(undefined1 **)(in_ECX + 0x34) = puVar8;
        param_1 = FUN_008f9df0(param_1);
        puVar7 = *(undefined1 **)(in_ECX + 0x34);
        puVar8 = *(undefined1 **)(in_ECX + 0x30);
        if (puVar7 < puVar8) {
          local_18 = puVar8 + (-1 - (int)puVar7);
        }
        else {
          local_18 = (undefined1 *)(*(int *)(in_ECX + 0x2c) - (int)puVar7);
        }
        if ((puVar7 == *(undefined1 **)(in_ECX + 0x2c)) &&
           (puVar4 = *(undefined1 **)(in_ECX + 0x28), puVar8 != puVar4)) {
          puVar7 = puVar4;
          if (puVar4 < puVar8) {
            local_18 = puVar8 + (-1 - (int)puVar4);
          }
          else {
            local_18 = (undefined1 *)(*(int *)(in_ECX + 0x2c) - (int)puVar4);
          }
        }
        if (local_18 == (undefined1 *)0x0) {
LAB_008fa3fd:
          *(uint *)(in_ECX + 0x20) = local_8;
          *(uint *)(in_ECX + 0x1c) = uVar9;
          in_EAX[1] = local_14;
          puVar8 = puVar7;
          goto LAB_008fa3bb;
        }
      }
LAB_008fa35b:
      *puVar7 = (char)puVar3[2];
      puVar8 = puVar7 + 1;
      local_18 = local_18 + -1;
      param_1 = 0;
LAB_008fa36b:
      *puVar3 = 0;
      break;
    case 7:
      if (7 < uVar9) {
        local_14 = local_14 + 1;
        uVar9 = uVar9 - 8;
        local_c = local_c + -1;
      }
      *(undefined1 **)(in_ECX + 0x34) = puVar8;
      uVar10 = FUN_008f9df0(param_1);
      puVar8 = *(undefined1 **)(in_ECX + 0x34);
      if (*(undefined1 **)(in_ECX + 0x30) != puVar8) {
        *(uint *)(in_ECX + 0x20) = local_8;
        *(uint *)(in_ECX + 0x1c) = uVar9;
        in_EAX[1] = local_14;
        iVar5 = *in_EAX;
        *in_EAX = (int)local_c;
        in_EAX[2] = (int)(local_c + (in_EAX[2] - iVar5));
        *(undefined1 **)(in_ECX + 0x34) = puVar8;
        FUN_008f9df0(uVar10);
        return;
      }
      *puVar3 = 8;
    case 8:
      *(uint *)(in_ECX + 0x20) = local_8;
      *(uint *)(in_ECX + 0x1c) = uVar9;
      in_EAX[1] = local_14;
      uVar10 = 1;
      goto LAB_008fa38d;
    case 9:
      uVar10 = 0xfffffffd;
      goto LAB_008fa37e;
    }
    uVar6 = *puVar3;
  }
  uVar10 = 0xfffffffe;
LAB_008fa37e:
  *(uint *)(in_ECX + 0x20) = local_8;
  *(uint *)(in_ECX + 0x1c) = uVar9;
  in_EAX[1] = local_14;
LAB_008fa38d:
  iVar5 = *in_EAX;
  *in_EAX = (int)local_c;
  in_EAX[2] = (int)(local_c + (in_EAX[2] - iVar5));
  *(undefined1 **)(in_ECX + 0x34) = puVar8;
  FUN_008f9df0(uVar10);
  return;
LAB_008fa3ab:
  *(uint *)(in_ECX + 0x20) = local_8;
  *(uint *)(in_ECX + 0x1c) = uVar9;
  in_EAX[1] = 0;
LAB_008fa3bb:
  iVar5 = *in_EAX;
  *in_EAX = (int)local_c;
  in_EAX[2] = (int)(local_c + (in_EAX[2] - iVar5));
  *(undefined1 **)(in_ECX + 0x34) = puVar8;
  FUN_008f9df0(param_1);
  return;
}

