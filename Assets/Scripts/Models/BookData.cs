using System.Collections.Generic;

namespace ARBook.Models
{
    [System.Serializable]
    public class BookData
    {
        public string id;
        public string title;
        public List<PageData> pages;
    }
}