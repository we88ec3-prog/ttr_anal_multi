
int FUN_008e5ee0(int param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint in_EAX;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  int iVar8;
  int local_8;
  
  puVar3 = *(uint **)(param_1 + 0x210);
  uVar1 = *(undefined4 *)(param_1 + 100);
  local_8 = 0;
  if (puVar3 == (uint *)0x0) {
    puVar3 = (uint *)FUN_008baee0(uVar1,0x1a4,&local_8);
    if (local_8 != 0) {
      return local_8;
    }
    puVar3[0x68] = 0;
    *(uint **)(param_1 + 0x210) = puVar3;
  }
  if (in_EAX != 0) {
    if (*puVar3 == 0) {
      uVar4 = FUN_008bc7d0(uVar1,0x20,0);
      puVar3[0x25] = uVar4;
      if (local_8 != 0) {
        return local_8;
      }
      uVar4 = FUN_008bc7d0(uVar1,0xc4,0);
      puVar3[0x36] = uVar4;
      if (local_8 != 0) {
        return local_8;
      }
      uVar4 = FUN_008bc7d0(uVar1,0x10,0);
      puVar3[0x48] = uVar4;
      if (local_8 != 0) {
        return local_8;
      }
      uVar4 = FUN_008bc7d0(uVar1,4,0,in_EAX * 2,0,&local_8);
      puVar3[0x22] = uVar4;
      if (local_8 != 0) {
        return local_8;
      }
      puVar3[0x23] = uVar4 + in_EAX * 4;
      puVar3[0x24] = param_1 + 0x84;
      puVar3[0x35] = param_1 + 0xa8;
      puVar3[0x47] = param_1 + 0x1cc;
      if (1 < in_EAX) {
        puVar6 = puVar3 + 0x26;
        iVar7 = in_EAX - 1;
        do {
          *puVar6 = puVar6[-1] + 0x20;
          puVar6[0x11] = puVar6[0x10] + 0xc4;
          puVar6[0x23] = puVar6[0x22] + 0x10;
          puVar6 = puVar6 + 1;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
      *puVar3 = in_EAX;
    }
    else if (*puVar3 != in_EAX) {
      return 3;
    }
  }
  if (param_2 != 0) {
    if ((puVar3[1] != 0) && (puVar3[1] != param_2)) {
      return 3;
    }
    puVar3[1] = param_2;
  }
  uVar4 = *puVar3;
  uVar2 = puVar3[1];
  if (((uVar4 != 0) && (uVar2 != 0)) && (puVar3[6] == 0)) {
    uVar5 = FUN_008bc7d0(uVar1,4,0,uVar4 * uVar2,0,&local_8);
    puVar3[6] = uVar5;
    if ((local_8 == 0) && (1 < uVar4)) {
      puVar6 = puVar3 + 7;
      iVar8 = uVar4 - 1;
      iVar7 = uVar2 * 4;
      do {
        *puVar6 = puVar3[6] + iVar7;
        puVar6 = puVar6 + 1;
        iVar7 = iVar7 + uVar2 * 4;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
    }
  }
  return local_8;
}

