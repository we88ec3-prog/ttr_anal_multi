
void FUN_007831c0(void)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 ***pppuVar4;
  int in_ECX;
  undefined1 *local_3c;
  int local_38;
  undefined1 local_31;
  undefined4 **local_30 [4];
  int local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009284c8;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar2;
  if ((**(int **)(in_ECX + 0x20) == 0) ||
     (**(int **)(in_ECX + 0x30) + **(uint **)(in_ECX + 0x20) <= **(uint **)(in_ECX + 0x20))) {
    if (*(int *)(in_ECX + 0x54) != 0) {
      if (**(int **)(in_ECX + 0x10) == in_ECX + 0x48) {
        uVar1 = *(undefined4 *)(in_ECX + 0x40);
        **(int **)(in_ECX + 0x10) = *(int *)(in_ECX + 0x3c);
        **(undefined4 **)(in_ECX + 0x20) = uVar1;
        **(undefined4 **)(in_ECX + 0x30) = 0;
      }
      if (*(int *)(in_ECX + 0x44) == 0) {
        FID_conflict__getc(*(FILE **)(in_ECX + 0x54));
      }
      else {
        local_1c = 0xf;
        local_20 = 0;
        local_30[0] = (undefined4 **)((uint)local_30[0] & 0xffffff00);
        local_8 = 0;
        iVar3 = FID_conflict__getc(*(FILE **)(in_ECX + 0x54));
        while (iVar3 != -1) {
          FUN_00429630(1,iVar3);
          pppuVar4 = (undefined4 ***)local_30[0];
          if (local_1c < 0x10) {
            pppuVar4 = local_30;
          }
          iVar3 = (**(code **)(**(int **)(in_ECX + 0x44) + 0x10))
                            (in_ECX + 0x4c,pppuVar4,(int)pppuVar4 + local_20,&local_38,&local_31,
                             local_30,&local_3c,uVar2);
          if (iVar3 < 0) break;
          if (iVar3 < 2) {
            if (local_3c != &local_31) {
              pppuVar4 = (undefined4 ***)local_30[0];
              if (local_1c < 0x10) {
                pppuVar4 = local_30;
              }
              for (iVar3 = (int)pppuVar4 + (local_20 - local_38); 0 < iVar3; iVar3 = iVar3 + -1) {
                _ungetc((int)*(char *)(iVar3 + -1 + local_38),*(FILE **)(in_ECX + 0x54));
              }
              FUN_00402c50();
              goto LAB_00783352;
            }
            pppuVar4 = (undefined4 ***)local_30[0];
            if (local_1c < 0x10) {
              pppuVar4 = local_30;
            }
            FUN_00402c80(0,local_38 - (int)pppuVar4);
          }
          else {
            if (iVar3 != 3) break;
            if (local_20 != 0) {
              pppuVar4 = (undefined4 ***)local_30[0];
              if (local_1c < 0x10) {
                pppuVar4 = local_30;
              }
              _memcpy_s(&local_31,1,pppuVar4,1);
              FUN_00402c50();
              goto LAB_00783352;
            }
          }
          iVar3 = FID_conflict__getc(*(FILE **)(in_ECX + 0x54));
        }
        FUN_00402c50();
      }
    }
  }
  else {
    **(int **)(in_ECX + 0x30) = **(int **)(in_ECX + 0x30) + -1;
    **(int **)(in_ECX + 0x20) = **(int **)(in_ECX + 0x20) + 1;
  }
LAB_00783352:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

