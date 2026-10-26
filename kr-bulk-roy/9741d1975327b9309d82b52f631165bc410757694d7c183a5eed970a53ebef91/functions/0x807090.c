
undefined4 FUN_00807090(undefined4 *param_1,undefined4 *param_2)

{
  HANDLE FileHandle;
  undefined4 *CompletionKey;
  undefined4 *puVar1;
  int *in_ECX;
  
  if (DAT_00fba858 == 0) {
    if (DAT_00fba85c == 0) {
      FUN_0049b000();
    }
    else {
      FUN_0049af60();
    }
  }
  CompletionKey = (undefined4 *)FUN_00805950(0);
  if (CompletionKey == (undefined4 *)0x0) {
    return 0;
  }
  *CompletionKey = *param_1;
  CompletionKey[1] = *param_2;
  CompletionKey[2] = param_2[1];
  CompletionKey[3] = param_2[2];
  FileHandle = (HANDLE)*CompletionKey;
  CompletionKey[4] = param_2[3];
  puVar1 = (undefined4 *)FUN_00806620();
  CreateIoCompletionPort(FileHandle,(HANDLE)*puVar1,(ULONG_PTR)CompletionKey,0);
  (**(code **)(*in_ECX + 0x14))(CompletionKey);
  return 1;
}

