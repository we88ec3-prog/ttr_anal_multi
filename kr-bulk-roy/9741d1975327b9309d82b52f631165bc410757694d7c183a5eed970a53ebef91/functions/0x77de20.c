
void FUN_0077de20(void)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  int in_ECX;
  undefined1 local_78 [8];
  char *local_70 [3];
  int local_64;
  uint local_60;
  int local_5c;
  int local_58;
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
  puStack_c = &LAB_009154c0;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_58 = in_ECX;
  local_14 = uVar3;
  FUN_0077dc90(in_ECX);
  if (*(int *)(in_ECX + 0x208) != 0) {
    local_54 = 0;
    do {
      (**(code **)(**(int **)(in_ECX + 0x208) + 0xf4))
                (*(int **)(in_ECX + 0x208),local_54,&local_54,uVar3);
      if (local_54 == 0) break;
      (**(code **)(**(int **)(in_ECX + 0x208) + 0x14))(*(int **)(in_ECX + 0x208),local_54,local_70);
      local_1c = 0xf;
      local_20 = 0;
      local_30[0] = local_30[0] & 0xffffff00;
      pcVar4 = local_70[0];
      do {
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      FUN_00402a70(local_70[0],(int)pcVar4 - (int)(local_70[0] + 1));
      local_8 = 0;
      local_64 = FUN_007b6f30(local_30);
      iVar2 = *(int *)(in_ECX + 0x210);
      if (local_64 == iVar2) {
LAB_0077df4c:
        local_5c = iVar2;
        piVar6 = &local_5c;
      }
      else {
        local_60 = *(uint *)(local_64 + 0x1c);
        uVar5 = local_60;
        if (local_20 < local_60) {
          uVar5 = local_20;
        }
        uVar5 = FUN_00407e70(uVar5);
        if (uVar5 == 0) {
          if (local_20 < local_60) {
            uVar5 = 0xffffffff;
          }
          else {
            uVar5 = (uint)(local_20 != local_60);
          }
        }
        if ((int)uVar5 < 0) goto LAB_0077df4c;
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
      if (iVar2 == *(int *)(local_58 + 0x210)) {
        puVar7 = (undefined4 *)FUN_00891268(0xc);
        if (puVar7 == (undefined4 *)0x0) {
          puVar7 = (undefined4 *)0x0;
        }
        else {
          *puVar7 = FoxUI::FXTechnique::vftable;
          puVar7[1] = 0;
          puVar7[2] = 0;
        }
        puVar7[1] = local_58;
        puVar7[2] = local_54;
        local_3c = 0xf;
        local_40 = 0;
        local_50[0] = local_50[0] & 0xffffff00;
        pcVar4 = local_70[0];
        do {
          cVar1 = *pcVar4;
          pcVar4 = pcVar4 + 1;
        } while (cVar1 != '\0');
        FUN_00402a70(local_70[0],(int)pcVar4 - (int)(local_70[0] + 1));
        local_8 = 1;
        local_34 = puVar7;
        uVar8 = FUN_0077e100(local_50);
        FUN_007e2910(in_ECX + 0x20c,local_78,uVar8);
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
      in_ECX = local_58;
    } while (local_54 != 0);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

