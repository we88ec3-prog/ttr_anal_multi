
char * FUN_00731bd0(void)

{
  undefined4 in_EAX;
  
  switch(in_EAX) {
  case 0:
    return "TIXML_NO_ERROR";
  case 1:
    return "TIXML_ERROR";
  case 2:
    return "TIXML_ERROR_OPENING_FILE";
  case 3:
    return "TIXML_ERROR_OUT_OF_MEMORY";
  case 4:
    return "TIXML_ERROR_PARSING_ELEMENT";
  case 5:
    return "TIXML_ERROR_FAILED_TO_READ_ELEMENT_NAME";
  case 6:
    return "TIXML_ERROR_READING_ELEMENT_VALUE";
  case 7:
    return "TIXML_ERROR_READING_ATTRIBUTES";
  case 8:
    return "TIXML_ERROR_PARSING_EMPTY";
  case 9:
    return "TIXML_ERROR_READING_END_TAG";
  case 10:
    return "TIXML_ERROR_PARSING_UNKNOWN";
  case 0xb:
    return "TIXML_ERROR_PARSING_COMMENT";
  case 0xc:
    return "TIXML_ERROR_PARSING_DECLARATION";
  case 0xd:
    return "TIXML_ERROR_DOCUMENT_EMPTY";
  case 0xe:
    return "TIXML_ERROR_EMBEDDED_NULL";
  case 0xf:
    return "TIXML_ERROR_PARSING_CDATA";
  case 0x10:
    return "TIXML_ERROR_DOCUMENT_TOP_ONLY";
  default:
    return "UNKNOWN";
  }
}

