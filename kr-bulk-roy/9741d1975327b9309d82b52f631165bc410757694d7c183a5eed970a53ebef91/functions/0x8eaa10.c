
int FUN_008eaa10(int param_1,int param_2)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  undefined1 *puVar6;
  uint uVar7;
  uint local_c;
  int local_8;
  
  uVar3 = *(undefined4 *)(param_2 + 0x1c);
  local_8 = (**(code **)(param_1 + 0x1fc))(param_1,0x68646d78,param_2,&local_c);
  if ((local_8 != 0) || (local_c < 8)) {
    return 0;
  }
  local_8 = FUN_008bc7a0(param_2,local_c,(undefined4 *)(param_1 + 0x2c0));
  if (local_8 == 0) {
    puVar2 = *(undefined1 **)(param_1 + 0x2c0);
    puVar1 = puVar2 + local_c;
    puVar6 = puVar2 + 8;
    uVar5 = (uint)CONCAT11(puVar2[2],puVar2[3]);
    uVar7 = CONCAT31(CONCAT21(CONCAT11(puVar2[4],puVar2[5]),puVar2[6]),puVar2[7]);
    if (0xfffeffff < uVar7) {
      uVar7 = uVar7 & 0xffff;
    }
    if (((CONCAT11(*puVar2,puVar2[1]) == 0) && (uVar5 < 0x100)) && (uVar7 < 0x10002)) {
      uVar3 = FUN_008bc7d0(uVar3,1,0,uVar5,0,&local_8);
      *(undefined4 *)(param_1 + 0x2d0) = uVar3;
      if (local_8 == 0) {
        uVar4 = 0;
        if (uVar5 != 0) {
          do {
            if (puVar1 < puVar6 + uVar7) break;
            *(undefined1 *)(uVar4 + *(int *)(param_1 + 0x2d0)) = *puVar6;
            uVar4 = uVar4 + 1;
            puVar6 = puVar6 + uVar7;
          } while (uVar4 < uVar5);
        }
        *(uint *)(param_1 + 0x2c8) = uVar4;
        *(uint *)(param_1 + 0x2cc) = uVar7;
        *(uint *)(param_1 + 0x2c4) = local_c;
        return 0;
      }
    }
    else {
      local_8 = 3;
    }
    FUN_008bab90(param_2,param_1 + 0x2c0);
    *(undefined4 *)(param_1 + 0x2c4) = 0;
  }
  return local_8;
}

