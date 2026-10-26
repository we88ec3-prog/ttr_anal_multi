
void FUN_00803ec0(void)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  undefined4 *in_ECX;
  int *piVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00909ae5;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = CNetwork::vftable;
  local_8 = 0;
  piVar5 = *(int **)in_ECX[3];
  if (piVar5 != (int *)in_ECX[3]) {
    do {
      closesocket(*(SOCKET *)piVar5[4]);
      FUN_0089120c(piVar5[4],uVar4);
      if (*(char *)((int)piVar5 + 0x15) == '\0') {
        piVar2 = (int *)piVar5[2];
        if (*(char *)((int)piVar2 + 0x15) == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x15);
          piVar5 = piVar2;
          piVar2 = (int *)*piVar2;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x15);
            piVar5 = piVar2;
            piVar2 = (int *)*piVar2;
          }
        }
        else {
          cVar1 = *(char *)(piVar5[1] + 0x15);
          piVar3 = (int *)piVar5[1];
          piVar2 = piVar5;
          while ((piVar5 = piVar3, cVar1 == '\0' && (piVar2 == (int *)piVar5[2]))) {
            cVar1 = *(char *)(piVar5[1] + 0x15);
            piVar3 = (int *)piVar5[1];
            piVar2 = piVar5;
          }
        }
      }
    } while (piVar5 != (int *)in_ECX[3]);
  }
  in_ECX[0x13] = 1;
  WaitForSingleObject((HANDLE)in_ECX[0x14],0xffffffff);
  CloseHandle((HANDLE)in_ECX[0x14]);
  DAT_00fba854 = 0;
  local_8._0_1_ = 2;
  FUN_005540c0(*(undefined4 *)in_ECX[7],(undefined4 *)in_ECX[7]);
  FUN_0089120c(in_ECX[7],uVar4);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_005540c0(*(undefined4 *)in_ECX[3],(undefined4 *)in_ECX[3]);
  FUN_0089120c(in_ECX[3]);
  *in_ECX = IThread::vftable;
  ExceptionList = local_10;
  return;
}

