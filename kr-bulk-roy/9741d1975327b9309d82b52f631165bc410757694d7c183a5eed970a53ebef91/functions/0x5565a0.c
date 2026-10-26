
void FUN_005565a0(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *in_ECX;
  undefined4 *puVar3;
  undefined **local_20 [3];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_0090b471;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar2 = (undefined4 *)FUN_00891268(0x24,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = DAT_00fc1904;
    puVar2[1] = DAT_00fc1904;
    puVar2[2] = DAT_00fc1904;
    *(undefined2 *)(puVar2 + 8) = 0;
    if (puVar2 + 3 != (undefined4 *)0x0) {
      puVar1 = in_ECX + 1;
      puVar2[3] = *in_ECX;
      puVar3 = puVar2 + 4;
      *puVar3 = 0;
      puVar2[5] = 0;
      puVar2[6] = 0;
      if (puVar3 != puVar1) {
        *puVar3 = 0;
        puVar2[5] = 0;
        puVar2[6] = 0;
        *puVar3 = *puVar1;
        puVar2[5] = in_ECX[2];
        puVar2[6] = in_ECX[3];
        *puVar1 = 0;
        in_ECX[2] = 0;
        in_ECX[3] = 0;
      }
    }
    ExceptionList = local_10;
    return;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_20,&local_14);
  local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_20,&DAT_00c857a8);
}

