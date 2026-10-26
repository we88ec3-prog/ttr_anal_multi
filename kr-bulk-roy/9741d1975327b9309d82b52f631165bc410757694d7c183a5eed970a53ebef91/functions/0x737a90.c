
void FUN_00737a90(void)

{
  HWND unaff_ESI;
  tagPOINT local_20;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_20.x = 0;
  local_20.y = 0;
  ClientToScreen(unaff_ESI,&local_20);
  GetClientRect(unaff_ESI,&local_18);
  OffsetRect(&local_18,local_20.x,local_20.y);
  ClipCursor(&local_18);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

