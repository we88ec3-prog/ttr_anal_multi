
void FUN_008f06c0(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  ushort uVar4;
  short sVar5;
  int in_EAX;
  int iVar6;
  int iVar7;
  ushort *puVar8;
  undefined4 uVar9;
  undefined4 local_18;
  int local_c;
  int local_8;
  
  iVar1 = *(int *)(in_EAX + 0x68);
  uVar2 = *(undefined4 *)(iVar1 + 0x1c);
  iVar3 = *(int *)(in_EAX + 0x2a4);
  local_8 = 0;
  *(undefined1 *)(iVar3 + 0x10) = 1;
  local_8 = (**(code **)(in_EAX + 0x1fc))();
  if ((local_8 == 0) && (local_8 = FUN_008babe0(iVar1,local_18), local_8 == 0)) {
    iVar6 = FUN_008b99c0(iVar1);
    iVar7 = FUN_008b99c0(iVar1);
    if ((iVar6 == 0x10000) && (iVar7 == **(int **)(iVar3 + 8))) {
      puVar8 = (ushort *)FUN_008bc7d0(uVar2,8,0,iVar7,0,&local_8);
      *(ushort **)(iVar3 + 0x14) = puVar8;
      if ((local_8 == 0) && (local_c = 0, 0 < iVar7)) {
        while( true ) {
          uVar4 = FUN_008b9960(iVar1);
          *puVar8 = uVar4;
          uVar9 = FUN_008bc7d0(uVar2,8,0,uVar4,0,&local_8);
          *(undefined4 *)(puVar8 + 2) = uVar9;
          if (local_8 != 0) break;
          iVar6 = 0;
          if (*puVar8 != 0) {
            do {
              sVar5 = FUN_008b9960(iVar1);
              *(int *)(*(int *)(puVar8 + 2) + iVar6 * 8) = sVar5 * 4;
              sVar5 = FUN_008b9960(iVar1);
              *(int *)(*(int *)(puVar8 + 2) + 4 + iVar6 * 8) = sVar5 * 4;
              iVar6 = iVar6 + 1;
            } while (iVar6 < (int)(uint)*puVar8);
          }
          local_c = local_c + 1;
          puVar8 = puVar8 + 4;
          if (iVar7 <= local_c) {
            FUN_008baca0(iVar1);
            return;
          }
        }
        local_c = local_c + -1;
        while (-1 < local_c) {
          FUN_008b9f80(uVar2,*(undefined4 *)(*(int *)(iVar3 + 0x14) + 4 + local_c * 8));
          local_c = local_c + -1;
          *(undefined4 *)(*(int *)(iVar3 + 0x14) + 0xc + local_c * 8) = 0;
        }
        FUN_008b9f80(uVar2,*(undefined4 *)(iVar3 + 0x14));
        *(undefined4 *)(iVar3 + 0x14) = 0;
      }
    }
    FUN_008baca0(iVar1);
  }
  return;
}

