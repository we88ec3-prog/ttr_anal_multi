
int FUN_008c7960(void)

{
  uint uVar1;
  int in_EAX;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int unaff_ESI;
  int local_8;
  
  uVar4 = *(undefined4 *)(in_EAX + 0x1c);
  *(undefined4 *)(unaff_ESI + 0x84) = 0;
  *(undefined4 *)(unaff_ESI + 0x88) = 0;
  *(undefined4 *)(unaff_ESI + 0x8c) = 0;
  uVar2 = FUN_008b9850();
  iVar3 = FUN_008b9c00();
  while( true ) {
    if (local_8 != 0) {
      return local_8;
    }
    if (iVar3 != 0x774f4646) {
      if (((((iVar3 != 0x10000) && (iVar3 != 0x74746366)) && (iVar3 != 0x4f54544f)) &&
          ((iVar3 != 0x74727565 && (iVar3 != 0x74797031)))) && (iVar3 != 0x20000)) {
        return 2;
      }
      *(undefined4 *)(unaff_ESI + 0x84) = 0x74746366;
      if (iVar3 == 0x74746366) {
        local_8 = FUN_008bacd0(in_EAX,&DAT_00bd8304,(undefined4 *)(unaff_ESI + 0x84));
        if (local_8 == 0) {
          uVar1 = *(uint *)(unaff_ESI + 0x8c);
          if (uVar1 == 0) {
            return 8;
          }
          if (*(uint *)(in_EAX + 4) >> 5 < uVar1) {
            return 10;
          }
          uVar4 = FUN_008bc7d0(uVar4,4,0,uVar1,0,&local_8);
          *(undefined4 *)(unaff_ESI + 0x90) = uVar4;
          if ((local_8 == 0) &&
             (local_8 = FUN_008babe0(in_EAX,*(int *)(unaff_ESI + 0x8c) * 4), local_8 == 0)) {
            iVar3 = 0;
            local_8 = 0;
            if (0 < *(int *)(unaff_ESI + 0x8c)) {
              do {
                uVar4 = FUN_008b99c0(in_EAX);
                *(undefined4 *)(*(int *)(unaff_ESI + 0x90) + iVar3 * 4) = uVar4;
                iVar3 = iVar3 + 1;
              } while (iVar3 < *(int *)(unaff_ESI + 0x8c));
            }
            FUN_008baca0(in_EAX);
            return local_8;
          }
        }
      }
      else {
        *(undefined4 *)(unaff_ESI + 0x88) = 0x10000;
        *(undefined4 *)(unaff_ESI + 0x8c) = 1;
        puVar5 = (undefined4 *)FUN_008baee0(uVar4,4,&local_8);
        *(undefined4 **)(unaff_ESI + 0x90) = puVar5;
        if (local_8 != 0) {
          return local_8;
        }
        *puVar5 = uVar2;
        local_8 = 0;
      }
      return local_8;
    }
    local_8 = FUN_008b97e0(in_EAX,uVar2);
    if (local_8 != 0) {
      return local_8;
    }
    local_8 = FUN_008c7420();
    if (local_8 != 0) break;
    in_EAX = *(int *)(unaff_ESI + 0x68);
    uVar2 = FUN_008b9850(in_EAX);
    iVar3 = FUN_008b9c00(in_EAX,&local_8);
  }
  return local_8;
}

