
void FUN_008cf180(void)

{
  longlong lVar1;
  uint *puVar2;
  int *in_EAX;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  int in_ECX;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  uint local_68 [16];
  int local_28;
  int local_24;
  int local_20;
  uint local_1c;
  int local_18;
  int local_14;
  uint local_10;
  uint local_c;
  uint *local_8;
  
  uVar7 = in_EAX[2];
  local_10 = uVar7 + *in_EAX * 0x28;
  local_14 = *(int *)(in_ECX * 0xcc + 200 + in_EAX[6]);
  uVar6 = 0;
  local_28 = in_EAX[4];
  local_1c = uVar7;
  uVar3 = uVar7;
  if (uVar7 < local_10) {
    do {
      if ((*(byte *)(uVar3 + 0x10) & 0x10) != 0) {
        uVar6 = uVar6 + 1;
      }
      uVar3 = uVar3 + 0x28;
    } while (uVar3 < local_10);
    if (uVar6 != 0) {
      if (uVar6 < 0x11) {
        puVar4 = local_68;
        local_8 = puVar4;
      }
      else {
        puVar4 = (uint *)FUN_008bc7d0(in_EAX[4],4,0,uVar6,0,&local_20);
        local_8 = puVar4;
        if (local_20 != 0) {
          return;
        }
      }
      local_c = 0;
      uVar3 = uVar7;
      puVar8 = puVar4;
      local_8 = puVar4;
      do {
        puVar2 = puVar8;
        if ((*(byte *)(uVar7 + 0x10) & 0x10) != 0) {
          while ((puVar4 < puVar2 &&
                 (uVar3 = local_1c, *(int *)(uVar7 + 0x1c) < *(int *)(puVar2[-1] + 0x1c)))) {
            *puVar2 = puVar2[-1];
            uVar3 = local_1c;
            puVar2 = puVar2 + -1;
          }
          local_c = local_c + 1;
          *puVar2 = uVar7;
          puVar8 = puVar8 + 1;
        }
        uVar7 = uVar7 + 0x28;
      } while (uVar7 < local_10);
      puVar8 = (uint *)(uVar3 + 0xc);
      local_1c = ((local_10 - uVar3) - 1) / 0x28 + 1;
      do {
        if ((puVar8[1] & 0x10) == 0) {
          uVar7 = *puVar8;
          if ((uVar7 & 2) != 0) {
            if ((((char)puVar8[2] == '\x04') || ((char)puVar8[2] != *(char *)((int)puVar8 + 9))) ||
               (((puVar8[1] & 0x40) == 0 && ((uVar7 & 4) == 0)))) goto LAB_008cf395;
            *puVar8 = uVar7 & 0xfffffffd;
          }
          uVar7 = 0;
          if (local_c == 0) {
LAB_008cf2b6:
            local_24 = puVar8[4] - *(int *)(*puVar4 + 0x1c);
            lVar1 = (longlong)local_24 * (longlong)local_14;
            lVar1 = lVar1 + (ulonglong)((int)(lVar1 >> 0x3f) + 0x8000);
            local_10 = ((uint)lVar1 >> 0x10) + (int)((ulonglong)lVar1 >> 0x20) * 0x10000;
            puVar8[6] = *(int *)(*puVar4 + 0x24) + local_10;
          }
          else {
            uVar3 = puVar8[4];
            do {
              if ((int)uVar3 < *(int *)(puVar4[uVar7] + 0x1c)) break;
              uVar7 = uVar7 + 1;
            } while (uVar7 < local_c);
            if (uVar7 == 0) goto LAB_008cf2b6;
            uVar7 = puVar4[uVar7 - 1];
            uVar6 = local_c;
            if (local_c == 0) {
LAB_008cf316:
              local_24 = uVar3 - *(int *)(puVar4[uVar6 - 1] + 0x1c);
              lVar1 = (longlong)local_24 * (longlong)local_14;
              lVar1 = lVar1 + (ulonglong)((int)(lVar1 >> 0x3f) + 0x8000);
              local_18 = ((uint)lVar1 >> 0x10) + (int)((ulonglong)lVar1 >> 0x20) * 0x10000;
              uVar7 = *(int *)(puVar4[uVar6 - 1] + 0x24) + local_18;
LAB_008cf38b:
              puVar8[6] = uVar7;
            }
            else {
              puVar4 = puVar4 + (local_c - 1);
              do {
                if (*(int *)(*puVar4 + 0x1c) < (int)uVar3) break;
                puVar4 = puVar4 + -1;
                uVar6 = uVar6 - 1;
              } while (uVar6 != 0);
              puVar4 = local_8;
              if (uVar6 == local_c) goto LAB_008cf316;
              uVar6 = local_8[uVar6];
              if (uVar3 == *(uint *)(uVar7 + 0x1c)) {
                uVar7 = *(uint *)(uVar7 + 0x24);
                goto LAB_008cf38b;
              }
              if (uVar3 != *(uint *)(uVar6 + 0x1c)) {
                iVar5 = FUN_008b7dc0(uVar3 - *(int *)(uVar7 + 0x1c),
                                     *(int *)(uVar6 + 0x24) - *(int *)(uVar7 + 0x24),
                                     *(uint *)(uVar6 + 0x1c) - *(int *)(uVar7 + 0x1c));
                uVar7 = iVar5 + *(int *)(uVar7 + 0x24);
                puVar4 = local_8;
                goto LAB_008cf38b;
              }
              puVar8[6] = *(uint *)(uVar6 + 0x24);
            }
          }
          puVar8[1] = puVar8[1] | 0x20;
        }
LAB_008cf395:
        puVar8 = puVar8 + 10;
        local_1c = local_1c + -1;
      } while (local_1c != 0);
      if (puVar4 != local_68) {
        FUN_008b9f80(local_28,puVar4);
      }
    }
  }
  return;
}

