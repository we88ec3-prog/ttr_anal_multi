
void FUN_008f90d0(int param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined1 local_10 [4];
  int local_c;
  int local_8;
  
  bVar1 = false;
  iVar4 = 0;
  uVar3 = 0x30;
  do {
    FUN_008f7580(param_1,uVar3,&local_c,local_10);
    if (local_c != 0) {
      iVar2 = FUN_008bd2a0(param_2,local_c,0x803,&local_8);
      if (iVar2 == 0) {
        if (bVar1) {
          if (local_8 != iVar4) {
            *(undefined1 *)(param_1 + 0x20) = 0;
            return;
          }
        }
        else {
          bVar1 = true;
          iVar4 = local_8;
        }
      }
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x3a);
  *(undefined1 *)(param_1 + 0x20) = 1;
  return;
}

