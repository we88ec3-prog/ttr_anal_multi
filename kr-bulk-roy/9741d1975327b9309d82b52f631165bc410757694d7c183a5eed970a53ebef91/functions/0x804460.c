
void FUN_00804460(void)

{
  void *pvVar1;
  uint uVar2;
  undefined4 *in_ECX;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090529c;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = CTCPInterface::vftable;
  local_8 = 1;
  if (in_ECX[0x29] != 0) {
    in_ECX[0x29] = 0;
    uVar3 = 0;
    if ((int)(in_ECX[0x26] - in_ECX[0x25]) >> 2 != 0) {
      do {
        SetEvent(*(HANDLE *)(*(int *)(in_ECX[0x25] + uVar3 * 4) + 8));
        uVar3 = uVar3 + 1;
      } while (uVar3 < (uint)((int)(in_ECX[0x26] - in_ECX[0x25]) >> 2));
    }
    WaitForMultipleObjects(in_ECX[0x29],(HANDLE *)in_ECX[0x2a],1,0xffffffff);
    uVar3 = 0;
    if ((int)(in_ECX[0x26] - in_ECX[0x25]) >> 2 != 0) {
      do {
        CloseHandle(*(HANDLE *)(*(int *)(in_ECX[0x25] + uVar3 * 4) + 8));
        CloseHandle(*(HANDLE *)(*(int *)(in_ECX[0x25] + uVar3 * 4) + 0xc));
        FUN_0089120c(*(undefined4 *)(in_ECX[0x25] + uVar3 * 4));
        uVar3 = uVar3 + 1;
      } while (uVar3 < (uint)((int)(in_ECX[0x26] - in_ECX[0x25]) >> 2));
    }
    pvVar1 = (void *)in_ECX[0x25];
    if (pvVar1 != (void *)in_ECX[0x26]) {
      FID_conflict__memcpy(pvVar1,(void *)in_ECX[0x26],0);
      in_ECX[0x26] = pvVar1;
    }
    pvVar1 = (void *)in_ECX[0x2a];
    if (pvVar1 != (void *)in_ECX[0x2b]) {
      FID_conflict__memcpy(pvVar1,(void *)in_ECX[0x2b],0);
      in_ECX[0x2b] = pvVar1;
    }
  }
  if (DAT_00fba854 != (undefined4 *)0x0) {
    (**(code **)*DAT_00fba854)(1,uVar2);
    DAT_00fba854 = (undefined4 *)0x0;
  }
  if (in_ECX[0x2a] != 0) {
    FUN_0089120c(in_ECX[0x2a]);
  }
  in_ECX[0x2a] = 0;
  in_ECX[0x2b] = 0;
  in_ECX[0x2c] = 0;
  if (in_ECX[0x25] != 0) {
    FUN_0089120c(in_ECX[0x25]);
  }
  in_ECX[0x25] = 0;
  in_ECX[0x26] = 0;
  in_ECX[0x27] = 0;
  ExceptionList = local_10;
  return;
}

