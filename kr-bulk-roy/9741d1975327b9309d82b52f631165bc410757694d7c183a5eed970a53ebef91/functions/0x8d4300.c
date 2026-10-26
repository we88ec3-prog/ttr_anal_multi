
int FUN_008d4300(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint local_10;
  uint local_c;
  int local_8;
  
  uVar1 = *(undefined4 *)(param_2 + 100);
  local_8 = FUN_008d3f00(param_1,&local_10,&local_c);
  if ((local_8 != 0) || (local_10 = FUN_008b9c70(param_1,&local_8), local_8 != 0)) {
    return local_8;
  }
  uVar4 = local_10 & 0xffffff00;
  if ((uVar4 == 0) || (uVar4 == 0x100)) {
    if (uVar4 == 0) {
      if ((local_10 & 4) == 0) {
        uVar2 = FUN_008b9c70(param_1,&local_8);
      }
      else {
        uVar2 = FUN_008b9c00(param_1,&local_8);
      }
    }
    else {
      if ((local_10 & 4) == 0) {
        uVar2 = FUN_008b9b20(param_1,&local_8);
      }
      else {
        uVar2 = FUN_008b9ab0(param_1,&local_8);
      }
      uVar2 = uVar2 & 0xffff;
    }
    if (local_8 == 0) {
      *(uint *)(param_2 + 0x120) = uVar2;
      if (uVar2 == 0) {
        return 8;
      }
      if (uVar4 == 0) {
        if (local_c / 0xc < uVar2) {
          return 8;
        }
      }
      else if (local_c / 5 < uVar2) {
        return 8;
      }
      iVar3 = FUN_008bc7d0(uVar1,0x10,0,uVar2,0,&local_8);
      *(int *)(param_2 + 0x124) = iVar3;
      if (local_8 == 0) {
        uVar4 = 0;
        if (uVar2 == 0) {
          return 0;
        }
        do {
          local_8 = FUN_008d3e70();
          *(undefined4 *)(iVar3 + 0xc) = 0;
          if (local_8 != 0) {
            FUN_008b9f80(uVar1,*(undefined4 *)(param_2 + 0x124));
            *(undefined4 *)(param_2 + 0x124) = 0;
            return local_8;
          }
          uVar4 = uVar4 + 1;
          iVar3 = iVar3 + 0x10;
          local_8 = 0;
        } while (uVar4 < uVar2);
        return 0;
      }
      return 0x40;
    }
  }
  return 3;
}

