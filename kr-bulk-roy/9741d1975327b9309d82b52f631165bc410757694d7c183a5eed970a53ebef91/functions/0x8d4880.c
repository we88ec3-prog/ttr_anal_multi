
void FUN_008d4880(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int in_ECX;
  undefined *puVar6;
  undefined4 *local_14;
  uint local_10;
  int local_c;
  int local_8;
  
  local_c = in_ECX + 0xc4;
  local_8 = FUN_008d3f00(param_1,&local_10,&local_14);
  if (local_8 == 0) {
    uVar5 = FUN_008b9c70(param_1,&local_8);
    if (local_8 == 0) {
      local_10 = uVar5 & 0xffffff00;
      if ((local_10 == 0) || (local_10 == 0x100)) {
        if ((uVar5 & 4) == 0) {
          puVar6 = &DAT_00be7f94;
        }
        else {
          puVar6 = &DAT_00be7fc8;
        }
        local_8 = FUN_008bacd0(param_1,puVar6,in_ECX + 0xc4);
        if (local_8 == 0) {
          local_14 = (undefined4 *)(in_ECX + 0xd8);
          local_8 = FUN_008d3e70();
          iVar4 = local_c;
          if (local_8 == 0) {
            puVar1 = (undefined4 *)(local_c + 0x24);
            local_8 = FUN_008d3e70();
            if (local_8 == 0) {
              if (local_10 == 0x100) {
                local_8 = FUN_008d3e70();
                if (local_8 == 0) {
                  FUN_008d3e70();
                  return;
                }
              }
              else {
                *(undefined4 *)(iVar4 + 0x34) = *local_14;
                *(undefined4 *)(iVar4 + 0x38) = local_14[1];
                uVar2 = local_14[3];
                *(undefined4 *)(iVar4 + 0x3c) = local_14[2];
                uVar3 = *puVar1;
                *(undefined4 *)(iVar4 + 0x40) = uVar2;
                *(undefined4 *)(iVar4 + 0x44) = uVar3;
                *(undefined4 *)(iVar4 + 0x48) = *(undefined4 *)(iVar4 + 0x28);
                *(undefined4 *)(iVar4 + 0x4c) = *(undefined4 *)(iVar4 + 0x2c);
                *(undefined4 *)(iVar4 + 0x50) = *(undefined4 *)(iVar4 + 0x30);
              }
            }
          }
        }
      }
    }
  }
  return;
}

