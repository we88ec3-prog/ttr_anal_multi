
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00806cf0(void)

{
  BOOL BVar1;
  int iVar2;
  int *in_ECX;
  DWORD local_28;
  LPOVERLAPPED local_24;
  ulong local_20;
  undefined1 local_1c [20];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_20 = 0;
  local_24 = (LPOVERLAPPED)0x0;
  local_28 = 0;
  if (in_ECX[0x16] != 0) {
    FUN_006f0400(0,"Start Worker Thread [threadid = %d]",in_ECX[1]);
  }
  while( true ) {
    while( true ) {
      if ((_DAT_00fe33b4 & 1) == 0) {
        _DAT_00fe33b4 = _DAT_00fe33b4 | 1;
        DAT_00fe33b8 = (HANDLE)0x0;
        _DAT_00fe33bc = 0;
        _DAT_00fe33c0 = 0;
        DAT_00fe33b8 = CreateIoCompletionPort((HANDLE)0xffffffff,(HANDLE)0x0,0,0);
        _atexit((_func_4879 *)&LAB_00bd0bb0);
      }
      BVar1 = GetQueuedCompletionStatus(DAT_00fe33b8,&local_28,&local_20,&local_24,0xffffffff);
      if (BVar1 != 0) break;
      if (local_24 != (LPOVERLAPPED)0x0) {
        if ((local_24 != (LPOVERLAPPED)(local_20 + 0xa030)) &&
           (local_24 == (LPOVERLAPPED)(local_20 + 0xa050))) {
          InterlockedDecrement((LONG *)(local_20 + 0xa0b8));
        }
        if (*(int *)(local_20 + 0xa0b8) == 0) {
          (**(code **)(*in_ECX + 0x24))(local_20,0);
          *(undefined4 *)(local_20 + 0xa0a8) = 1;
        }
      }
    }
    if (local_20 == 1) break;
    if (local_24 == (LPOVERLAPPED)0x0) {
      if (in_ECX[0x16] != 0) {
        FUN_006f0400(2,"get IO Ctx Failed.");
      }
    }
    else if (local_28 == 0) {
      (**(code **)(*in_ECX + 0x24))(local_20,0);
      *(undefined4 *)(local_20 + 0xa0a8) = 1;
    }
    else if (local_24 == (LPOVERLAPPED)(local_20 + 0xa030)) {
      in_ECX[0xb] = in_ECX[0xb] + local_28;
      in_ECX[0xf] = in_ECX[0xf] + 1;
      if (*(int *)(local_20 + 0xa0ac) != 0) {
        iVar2 = FUN_00807b40(local_20);
        if (iVar2 == 0) {
          if (*(int *)(local_20 + 0xa0b0) == 0) {
            if (in_ECX[0x16] != 0) {
              FUN_004c4330("%d.%d.%d.%d",*(undefined1 *)(local_20 + 8),*(undefined1 *)(local_20 + 9)
                           ,*(undefined1 *)(local_20 + 10),*(undefined1 *)(local_20 + 0xb));
              FUN_006f0400(2,"Preamble-protocol violated. Kicked.[IP: %s]",local_1c);
            }
            *(undefined4 *)(local_20 + 0xa0b0) = 1;
          }
        }
        else {
          (**(code **)(*in_ECX + 0x14))(local_20);
        }
      }
    }
    else if (local_24 == (LPOVERLAPPED)(local_20 + 0xa050)) {
      in_ECX[10] = in_ECX[10] + local_28;
      in_ECX[0xe] = in_ECX[0xe] + 1;
      if (*(int *)(local_20 + 0xa0ac) != 0) {
        FUN_008077b0();
      }
      *(bool *)(local_20 + 0xa024) = *(int *)(local_20 + 41000) != 0;
      InterlockedDecrement((LONG *)(local_20 + 0xa0b8));
    }
  }
  if (in_ECX[0x16] != 0) {
    FUN_006f0400(0,"Thread Killed");
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

