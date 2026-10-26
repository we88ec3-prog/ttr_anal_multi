
void FUN_00807f20(void)

{
  undefined4 *unaff_ESI;
  int iVar1;
  
  iVar1 = 0;
  if (0 < (int)unaff_ESI[1]) {
    do {
      PostQueuedCompletionStatus((HANDLE)*unaff_ESI,0,1,(LPOVERLAPPED)0x0);
      iVar1 = iVar1 + 1;
    } while (iVar1 < (int)unaff_ESI[1]);
  }
  WaitForMultipleObjects(unaff_ESI[1],(HANDLE *)unaff_ESI[2],1,0xffffffff);
  iVar1 = 0;
  if (0 < (int)unaff_ESI[1]) {
    do {
      CloseHandle(*(HANDLE *)(unaff_ESI[2] + iVar1 * 4));
      iVar1 = iVar1 + 1;
    } while (iVar1 < (int)unaff_ESI[1]);
  }
  if (unaff_ESI[2] != 0) {
    FUN_00891d3d(unaff_ESI[2]);
    unaff_ESI[2] = 0;
  }
  return;
}

