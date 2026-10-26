
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 * FUN_004073c0(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined1 local_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00925ad3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  _DAT_00faaf38 = 0;
  DAT_00faaf3c = 0;
  _DAT_00faaf44 = 0;
  _DAT_00faaf48 = 1;
  DAT_00faaf54 = 0;
  DAT_00faaf50 = FUN_00820120(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  *(int *)DAT_00faaf50 = DAT_00faaf50;
  *(int *)(DAT_00faaf50 + 4) = DAT_00faaf50;
  *(int *)(DAT_00faaf50 + 8) = DAT_00faaf50;
  *(undefined1 *)(DAT_00faaf50 + 0x18) = 1;
  *(undefined1 *)(DAT_00faaf50 + 0x19) = 1;
  local_8 = 0;
  DAT_00faaf5c = (undefined1 *)0x0;
  DAT_00faaf60 = (undefined1 *)0x0;
  DAT_00faaf64 = (undefined1 *)0x0;
  FUN_00407c90();
  local_8._0_1_ = 1;
  DAT_00faaf6c = (undefined1 *)0x0;
  DAT_00faaf70 = (undefined1 *)0x0;
  DAT_00faaf74 = (undefined1 *)0x0;
  FUN_00407c90();
  local_8 = CONCAT31(local_8._1_3_,2);
  iVar3 = 0;
  local_11 = 0;
  puVar4 = DAT_00faaf5c;
  do {
    if ((&local_11 < DAT_00faaf60) && (puVar4 <= &local_11)) {
      iVar5 = (int)&local_11 - (int)puVar4;
      if (DAT_00faaf60 == DAT_00faaf64) {
        if ((int)DAT_00faaf60 - (int)puVar4 == -1) goto LAB_004075dc;
        uVar1 = ((int)DAT_00faaf60 - (int)puVar4) + 1;
        uVar2 = (int)DAT_00faaf64 - (int)puVar4;
        if (uVar2 < uVar1) {
          if (-(uVar2 >> 1) - 1 < uVar2) {
            uVar2 = 0;
          }
          else {
            uVar2 = uVar2 + (uVar2 >> 1);
          }
          if (uVar2 < uVar1) {
            uVar2 = uVar1;
          }
          FUN_00407d50(uVar2);
          puVar4 = DAT_00faaf5c;
        }
      }
      if (DAT_00faaf60 != (undefined1 *)0x0) {
        *DAT_00faaf60 = puVar4[iVar5];
        puVar4 = DAT_00faaf5c;
      }
    }
    else {
      if (DAT_00faaf60 == DAT_00faaf64) {
        if ((int)DAT_00faaf60 - (int)puVar4 == -1) goto LAB_004075dc;
        uVar1 = ((int)DAT_00faaf60 - (int)puVar4) + 1;
        uVar2 = (int)DAT_00faaf64 - (int)puVar4;
        if (uVar2 < uVar1) {
          if (-(uVar2 >> 1) - 1 < uVar2) {
            uVar2 = 0;
          }
          else {
            uVar2 = uVar2 + (uVar2 >> 1);
          }
          if (uVar2 < uVar1) {
            uVar2 = uVar1;
          }
          FUN_00407d50(uVar2);
          puVar4 = DAT_00faaf5c;
        }
      }
      if (DAT_00faaf60 != (undefined1 *)0x0) {
        *DAT_00faaf60 = 0;
        puVar4 = DAT_00faaf5c;
      }
    }
    DAT_00faaf60 = DAT_00faaf60 + 1;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0xd);
  local_11 = 0;
  iVar3 = 0;
  puVar4 = DAT_00faaf6c;
  do {
    if ((&local_11 < DAT_00faaf70) && (puVar4 <= &local_11)) {
      iVar5 = (int)&local_11 - (int)puVar4;
      if (DAT_00faaf70 == DAT_00faaf74) {
        if ((int)DAT_00faaf70 - (int)puVar4 == -1) {
LAB_004075dc:
                    /* WARNING: Subroutine does not return */
          FUN_0087db30("vector<T> too long");
        }
        uVar1 = ((int)DAT_00faaf70 - (int)puVar4) + 1;
        uVar2 = (int)DAT_00faaf74 - (int)puVar4;
        if (uVar2 < uVar1) {
          if (-(uVar2 >> 1) - 1 < uVar2) {
            uVar2 = 0;
          }
          else {
            uVar2 = uVar2 + (uVar2 >> 1);
          }
          if (uVar2 < uVar1) {
            uVar2 = uVar1;
          }
          FUN_00407d50(uVar2);
          puVar4 = DAT_00faaf6c;
        }
      }
      if (DAT_00faaf70 != (undefined1 *)0x0) {
        *DAT_00faaf70 = puVar4[iVar5];
        puVar4 = DAT_00faaf6c;
      }
    }
    else {
      if (DAT_00faaf70 == DAT_00faaf74) {
        if ((int)DAT_00faaf70 - (int)puVar4 == -1) goto LAB_004075dc;
        uVar1 = ((int)DAT_00faaf70 - (int)puVar4) + 1;
        uVar2 = (int)DAT_00faaf74 - (int)puVar4;
        if (uVar2 < uVar1) {
          if (-(uVar2 >> 1) - 1 < uVar2) {
            uVar2 = 0;
          }
          else {
            uVar2 = uVar2 + (uVar2 >> 1);
          }
          if (uVar2 < uVar1) {
            uVar2 = uVar1;
          }
          FUN_00407d50(uVar2);
          puVar4 = DAT_00faaf6c;
        }
      }
      if (DAT_00faaf70 != (undefined1 *)0x0) {
        *DAT_00faaf70 = 0;
        puVar4 = DAT_00faaf6c;
      }
    }
    DAT_00faaf70 = DAT_00faaf70 + 1;
    iVar3 = iVar3 + 1;
    if (0xc < iVar3) {
      FUN_00407780();
      ExceptionList = local_10;
      return &DAT_00faaf38;
    }
  } while( true );
}

