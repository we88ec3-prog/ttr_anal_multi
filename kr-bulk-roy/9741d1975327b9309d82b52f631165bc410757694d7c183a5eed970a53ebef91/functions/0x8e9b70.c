
int FUN_008e9b70(int param_1)

{
  undefined4 uVar1;
  ushort *puVar2;
  int iVar3;
  int in_EAX;
  undefined4 *puVar4;
  undefined4 uVar5;
  ushort *puVar6;
  uint uVar7;
  int iVar8;
  int unaff_EBX;
  ushort *puVar9;
  int *local_c;
  int local_8;
  
  uVar1 = *(undefined4 *)(in_EAX + 0x1c);
  puVar9 = *(ushort **)(in_EAX + 0x20);
  puVar2 = *(ushort **)(in_EAX + 0x24);
  local_8 = 0;
  if (puVar2 < (ushort *)((int)puVar9 + 0x65U)) {
    local_8 = 2;
  }
  else {
    puVar6 = (ushort *)((int)puVar9 + *(ushort *)((int)puVar9 + 99) + 0x75);
    if (puVar2 < puVar6 + 9) {
      return 0;
    }
    if (*puVar6 < 0x12) {
      return 0;
    }
    puVar6 = (ushort *)(*(int *)(puVar6 + 7) + (int)puVar9);
    if (puVar6 == puVar9) {
      return 0;
    }
    puVar9 = puVar6 + 1;
    if (puVar9 <= puVar2) {
      uVar7 = (uint)*puVar6;
      *(uint *)(param_1 + 0x28) = uVar7;
      if (puVar9 + uVar7 * 2 <= puVar2) {
        if (uVar7 == 0) {
          return 0;
        }
        puVar4 = (undefined4 *)FUN_008bc7d0(uVar1,0x10,0,uVar7,0,&local_8);
        *(undefined4 **)(param_1 + 0x24) = puVar4;
        if (local_8 == 0) {
          iVar3 = *(int *)(unaff_EBX + 0x5c);
          puVar2 = puVar9 + *(int *)(param_1 + 0x28) * 2;
          iVar8 = 0;
          if (0 < *(int *)(unaff_EBX + 0x24)) {
            local_c = *(int **)(unaff_EBX + 0x28);
            do {
              if (*(short *)(*local_c + 8) == 7) {
                local_8 = FUN_008ba740();
                if (local_8 != 0) goto LAB_008e9d32;
                break;
              }
              local_c = local_c + 1;
              iVar8 = iVar8 + 1;
            } while (iVar8 < *(int *)(unaff_EBX + 0x24));
          }
          for (; puVar9 < puVar2; puVar9 = puVar9 + 2) {
            uVar5 = FUN_008b8ce0();
            *puVar4 = uVar5;
            uVar5 = FUN_008b8ce0();
            puVar4[1] = uVar5;
            puVar4[2] = (int)(short)((ushort)*(byte *)((int)puVar9 + 3) << 8) |
                        (uint)(byte)puVar9[1];
            puVar4[3] = 0;
            puVar4 = puVar4 + 4;
          }
          if (iVar3 != 0) {
            local_8 = FUN_008ba740();
          }
          if ((local_8 == 0) &&
             (_qsort(*(void **)(param_1 + 0x24),*(size_t *)(param_1 + 0x28),0x10,FUN_008e9b40),
             local_8 == 0)) {
            return 0;
          }
        }
        goto LAB_008e9d32;
      }
    }
    local_8 = 2;
  }
LAB_008e9d32:
  FUN_008b9f80(uVar1,*(undefined4 *)(param_1 + 0x24));
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  return local_8;
}

