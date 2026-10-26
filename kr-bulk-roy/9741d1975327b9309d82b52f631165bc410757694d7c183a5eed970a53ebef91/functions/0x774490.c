
void FUN_00774490(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  int in_ECX;
  undefined1 local_80 [8];
  char *local_78 [3];
  uint local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  uint local_58;
  int local_54;
  uint local_50 [4];
  undefined4 local_40;
  uint local_3c;
  undefined4 *local_34;
  uint local_30 [4];
  uint local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00915500;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_60 = in_ECX;
  FUN_0077de20(local_14);
  iVar3 = *(int *)(in_ECX + 0x268);
  local_58 = 0;
  if (*(int *)(in_ECX + 0x26c) - iVar3 >> 2 != 0) {
    do {
      iVar3 = *(int *)(iVar3 + local_58 * 4);
      local_5c = iVar3;
      FUN_0077dc90(iVar3);
      if (*(int *)(iVar3 + 0x208) != 0) {
        local_54 = 0;
        do {
          (**(code **)(**(int **)(iVar3 + 0x208) + 0xf4))
                    (*(int **)(iVar3 + 0x208),local_54,&local_54);
          in_ECX = local_60;
          if (local_54 == 0) break;
          (**(code **)(**(int **)(iVar3 + 0x208) + 0x14))
                    (*(int **)(iVar3 + 0x208),local_54,local_78);
          local_1c = 0xf;
          local_20 = 0;
          local_30[0] = local_30[0] & 0xffffff00;
          pcVar4 = local_78[0];
          do {
            cVar1 = *pcVar4;
            pcVar4 = pcVar4 + 1;
          } while (cVar1 != '\0');
          FUN_00402a70(local_78[0],(int)pcVar4 - (int)(local_78[0] + 1));
          local_8 = 0;
          local_64 = FUN_007b6f30(local_30);
          iVar2 = *(int *)(iVar3 + 0x210);
          if (local_64 == iVar2) {
LAB_007745ec:
            local_68 = iVar2;
            piVar6 = &local_68;
          }
          else {
            local_6c = *(uint *)(local_64 + 0x1c);
            uVar5 = local_6c;
            if (local_20 < local_6c) {
              uVar5 = local_20;
            }
            uVar5 = FUN_00407e70(uVar5);
            if (uVar5 == 0) {
              if (local_20 < local_6c) {
                uVar5 = 0xffffffff;
              }
              else {
                uVar5 = (uint)(local_20 != local_6c);
              }
            }
            if ((int)uVar5 < 0) goto LAB_007745ec;
            piVar6 = &local_64;
          }
          iVar2 = *piVar6;
          local_8 = 0xffffffff;
          if (0xf < local_1c) {
            FUN_0089120c(local_30[0]);
          }
          local_1c = 0xf;
          local_20 = 0;
          local_30[0] = local_30[0] & 0xffffff00;
          if (iVar2 == *(int *)(local_5c + 0x210)) {
            puVar7 = (undefined4 *)FUN_00891268(0xc);
            if (puVar7 == (undefined4 *)0x0) {
              puVar7 = (undefined4 *)0x0;
            }
            else {
              *puVar7 = FoxUI::FXTechnique::vftable;
              puVar7[1] = 0;
              puVar7[2] = 0;
            }
            puVar7[1] = local_5c;
            puVar7[2] = local_54;
            local_3c = 0xf;
            local_40 = 0;
            local_50[0] = local_50[0] & 0xffffff00;
            pcVar4 = local_78[0];
            do {
              cVar1 = *pcVar4;
              pcVar4 = pcVar4 + 1;
            } while (cVar1 != '\0');
            FUN_00402a70(local_78[0],(int)pcVar4 - (int)(local_78[0] + 1));
            local_8 = 1;
            local_34 = puVar7;
            uVar8 = FUN_0077e100(local_50);
            FUN_007e2910(iVar3 + 0x20c,local_80,uVar8);
            local_8 = 0xffffffff;
            if (0xf < local_3c) {
              FUN_0089120c(local_50[0]);
            }
            local_3c = 0xf;
            local_40 = 0;
            local_50[0] = local_50[0] & 0xffffff00;
          }
          else {
            *(int *)(*(int *)(iVar2 + 0x28) + 8) = local_54;
          }
          in_ECX = local_60;
          iVar3 = local_5c;
        } while (local_54 != 0);
      }
      iVar3 = *(int *)(in_ECX + 0x268);
      local_58 = local_58 + 1;
    } while (local_58 < (uint)(*(int *)(in_ECX + 0x26c) - iVar3 >> 2));
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

